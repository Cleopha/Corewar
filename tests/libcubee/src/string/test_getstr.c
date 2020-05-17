/*
** EPITECH PROJECT, 2019
** C-LIBS
** File description:
** Test getstr function
*/

#include "unit_test.h"

Test(clib_string_getstr, normal_test)
{
    char *result = getstr("Hello World !", 6, 10);

    cr_assert_str_eq(result, "World");
    cfree(result, NULL);
}

Test(clib_string_getstr, malloc_error_test)
{
    char *result;

    malloc_error_test = 1;
    result = getstr("Hello World !", 6, 10);
    cr_assert(!result);
    cfree(result, NULL);
}

Test(clib_string_getstr, to_over_test)
{
    char *result = getstr("Hello World !", 6, 1000);

    cr_assert(!result);
    cfree(result, NULL);
}

Test(clib_string_getstr, fom_over_test)
{
    char *result = getstr("Hello World !", 500, 1000);

    cr_assert(!result);
    cfree(result, NULL);
}

Test(clib_string_getstr, normal_test_inverted_value)
{
    char *result = getstr("Hello World !", 10, 6);

    cr_assert_str_eq(result, "World");
    cfree(result, NULL);
}

Test(clib_string_getstr, empty_str_test)
{
    char *result = getstr(NULL, 10, 6);

    cr_assert(!result);
    cfree(result, NULL);
}
