/*
** EPITECH PROJECT, 2019
** C-LIB
** File description:
** ntoa
*/

#include "unit_test.h"

Test(clib_integer_ntoa, normal_base_test)
{
    char *positive_value = ntoa(1024, BASE_10, SIGNED);
    char *negative_value = ntoa(-1024, BASE_10, SIGNED);

    cr_assert_str_eq(positive_value, "1024");
    cr_assert_str_eq(negative_value, "-1024");
    cfree(positive_value, NULL);
    cfree(negative_value, NULL);
}

Test(clib_integer_ntoa, normal_2_test)
{
    char *value = ntoa(1024, BASE_2, NO_SIGNED);

    cr_assert_str_eq(value, "10000000000");
    cfree(value, NULL);
}

Test(clib_integer_ntoa, negative_nosigned_test)
{
    char *value = ntoa(-1, BASE_10, NO_SIGNED);

    cr_assert_str_eq(value, "18446744073709551615");
    cfree(value, NULL);
}

Test(clib_integer_ntoa, no_base_test)
{
    char *value = ntoa(1024, NULL, SIGNED);

    cr_assert(!value);
    cfree(value, NULL);
}

Test(clib_integer_ntoa, malloc_error_test)
{
    char *value;

    malloc_error_test = 1;
    value = ntoa(1024, BASE_10, SIGNED);
    cr_assert(!value);
    cfree(value, NULL);
}
