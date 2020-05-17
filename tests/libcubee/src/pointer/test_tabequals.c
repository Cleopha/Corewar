/*
** EPITECH PROJECT, 2019
** C-LIB
** File description:
** tabequals units tests
*/

#include "unit_test.h"

struct test_s {
    char data;
    void *random;
};

Test(clib_pointer_tabequals, normal_test)
{
    int result = tabequals("Hello", "Hello", sizeof(char));

    cr_assert_eq(result, 1);
}

Test(clib_pointer_tabequals, normal_test_2)
{
    int result = tabequals("Hello", "Hella", sizeof(char));

    cr_assert_eq(result, 0);
}

Test(clib_pointer_tabequals, normal_test_3)
{
    int result = tabequals("Hello", "Helloo", sizeof(char));

    cr_assert_eq(result, 0);
}

Test(clib_pointer_tabequals, normal_struct_test)
{
    static const struct test_s data1[3] = {{1, NULL}, {2, NULL}, {0, NULL}};
    static const struct test_s data2[3] = {{1, NULL}, {2, NULL}, {0, NULL}};
    int result = tabequals(data1, data2, sizeof(struct test_s));

    cr_assert_eq(result, 1);
}

Test(clib_pointer_tabequals, normal_struct_test_2)
{
    static const struct test_s data1[3] = {{2, NULL}, {1, NULL}, {0, NULL}};
    static const struct test_s data2[3] = {{2, NULL}, {2, NULL}, {0, NULL}};
    int result = tabequals(data1, data2, sizeof(struct test_s));

    cr_assert_eq(result, 0);
}

Test(clib_pointer_tabequals, null_str_test)
{
    int result = tabequals(NULL, "Hello", sizeof(char));

    cr_assert_eq(result, 0);
}

Test(clib_pointer_tabequals, null_str_test_2)
{
    int result = tabequals("Hello", NULL, sizeof(char));

    cr_assert_eq(result, 0);
}

Test(clib_pointer_tabequals, null_str_test_3)
{
    int result = tabequals(NULL, NULL, sizeof(char));

    cr_assert_eq(result, 0);
}

Test(clib_pointer_tabequals, null_unit_size_test)
{
    int result = tabequals("Hello", "Hello", 0);

    cr_assert_eq(result, 0);
}
