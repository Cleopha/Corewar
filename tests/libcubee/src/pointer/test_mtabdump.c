/*
** EPITECH PROJECT, 2019
** C-LIB
** File description:
** mtabdump units tests
*/

#include "unit_test.h"

Test(clib_pointer_mtabdump, normal_test)
{
    static const char *str = "Hello World !";
    char *result = mtabdump(str, sizeof(char), 1);

    cr_assert_str_eq(result, str);
    cfree(result, NULL);
}

Test(clib_pointer_mtabdump, normal_double_test)
{
    static const char *data[3] = {"Hello", "World", NULL};
    char **result = mtabdump(data, sizeof(char), 2);

    cr_assert_str_eq(result[0], "Hello");
    cr_assert_str_eq(result[1], "World");
    cr_assert(!result[2]);
    mcfree(result, 1, NULL);
}

Test(clib_pointer_mtabdump, null_str_test)
{
    char *result = mtabdump(NULL, sizeof(char), 1);

    cr_assert(!result);
    cfree(result, NULL);
}

Test(clib_pointer_mtabdump, null_unit_size_test)
{
    static const char *str = "Hello World !";
    char *result = mtabdump(str, 0, 1);

    cr_assert(!result);
    cfree(result, NULL);
}

Test(clib_pointer_mtabdump, null_level_test)
{
    static const char *str = "Hello World !";
    char *result = mtabdump(str, sizeof(char), 0);

    cr_assert(!result);
    cfree(result, NULL);
}

Test(clib_pointer_mtabdump, malloc_error_test)
{
    static const char *str = "Hello World !";
    char *result;

    malloc_error_test = 1;
    result = mtabdump(str, sizeof(char), 1);
    cr_assert(!result);
    cfree(result, NULL);
}
