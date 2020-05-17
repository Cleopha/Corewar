/*
** EPITECH PROJECT, 2019
** C-LIBS
** File description:
** Test stredit function
*/

#include "unit_test.h"

Test(clib_string_stredit, normal_test)
{
    char *result = stredit("Coucou MrCubee !", 7, 14, "Anonyme");

    cr_assert_str_eq(result, "Coucou Anonyme !");
    cfree(result, NULL);
}

Test(clib_string_stredit, malloc_error_test, .timeout = 2)
{
    char *result;

    malloc_error_test = 1;
    result = stredit("Coucou MrCubee !", 7, 14, "Anonyme");
    cr_assert(!result);
    cfree(result, NULL);
}

Test(clib_string_stredit, to_over_test)
{
    char *result = stredit("Coucou MrCubee !", 7, 1000, "Anonyme");

    cr_assert(!result);
    cfree(result, NULL);
}

Test(clib_string_stredit, from_over_test)
{
    char *result = stredit("Coucou MrCubee !", 500, 1000, "Anonyme");

    cr_assert(!result);
    cfree(result, NULL);
}

Test(clib_string_stredit, normal_test_inverted_value)
{
    char *result = stredit("Coucou MrCubee !", 14, 7, "Anonyme");

    cr_assert_str_eq(result, "Coucou Anonyme !");
    cfree(result, NULL);
}

Test(clib_string_stredit, empty_replace_test)
{
    char *result = stredit("Coucou MrCubee !", 7, 14, NULL);

    cr_assert_str_eq(result, "Coucou  !");
    cfree(result, NULL);
}

Test(clib_string_stredit, empty_str_test)
{
    char *result = stredit(NULL, 7, 14, "Anonyme");

    cr_assert(!result);
    cfree(result, NULL);
}
