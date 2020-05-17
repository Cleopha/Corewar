/*
** EPITECH PROJECT, 2019
** C-LIB
** File description:
** tabdump units tests
*/

#include "unit_test.h"

struct test_s {
    char data;
    void *random;
};

Test(clib_pointer_tabstart, normal_test)
{
    int result = tabstart("Hello", "Hel", sizeof(char));

    cr_assert_eq(result, 1);
}

Test(clib_pointer_tabstart, normal_test_2)
{
    int result = tabstart("Hello", "Heo", sizeof(char));

    cr_assert_eq(result, 0);
}

Test(clib_pointer_tabstart, normal_test_3)
{
    int result = tabstart("Hello", "H", sizeof(char));

    cr_assert_eq(result, 1);
}

Test(clib_pointer_tabstart, normal_struct_test)
{
    static const struct test_s data1[3] = {{1, NULL}, {2, NULL}, {0, NULL}};
    static const struct test_s data2[3] = {{1, NULL}, {0, NULL}};
    int result = tabstart(data1, data2, sizeof(struct test_s));

    cr_assert_eq(result, 1);
}

Test(clib_pointer_tabstart, normal_struct_test_2)
{
    static const struct test_s data1[3] = {{2, NULL}, {1, NULL}, {0, NULL}};
    static const struct test_s data2[3] = {{2, NULL}, {2, NULL}, {0, NULL}};
    int result = tabstart(data1, data2, sizeof(struct test_s));

    cr_assert_eq(result, 0);
}

Test(clib_pointer_tabstart, normal_struct_test_3)
{
    static const struct test_s data1[3] = {{1, NULL}, {2, NULL}, {0, NULL}};
    static const struct test_s data2[4] = {{1, NULL}, {2, NULL}, {3, NULL},
        {0, NULL}};
    int result = tabstart(data1, data2, sizeof(struct test_s));

    cr_assert_eq(result, 0);
}

Test(clib_pointer_tabstart, null_str_test)
{
    int result = tabstart(NULL, "Hello", sizeof(char));

    cr_assert_eq(result, 0);
}

Test(clib_pointer_tabstart, null_str_test_2)
{
    int result = tabstart("Hello", NULL, sizeof(char));

    cr_assert_eq(result, 0);
}

Test(clib_pointer_tabstart, null_str_test_3)
{
    int result = tabstart(NULL, NULL, sizeof(char));

    cr_assert_eq(result, 0);
}

Test(clib_pointer_tabstart, null_unit_size_test)
{
    int result = tabstart("Hello", "Hello", 0);

    cr_assert_eq(result, 0);
}
