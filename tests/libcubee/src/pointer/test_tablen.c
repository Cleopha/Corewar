/*
** EPITECH PROJECT, 2019
** C-LIBS
** File description:
** Test tablen function
*/

#include "unit_test.h"

struct test_s {
    char data;
    void *random;
};

Test(clib_pointer_tablen, normal_test)
{
    size_t result = tablen("Hello World", sizeof(char));

    cr_assert_eq(result, 11);
}

Test(clib_pointer_tablen, zero_sizeof)
{
    size_t result = tablen("Hello World", 0);

    cr_assert_eq(result, 0);
}

Test(clib_pointer_tablen, empty_str)
{
    size_t result = tablen(NULL, sizeof(char));

    cr_assert_eq(result, 0);
}

Test(clib_pointer_tablen, normal_test_struct)
{
    struct test_s *datas = my_malloc(2, sizeof(struct test_s));
    size_t result;

    cr_assert(datas);
    if (!datas)
        return;
    datas[0].data = '0';
    datas[1].data = '1';
    result = tablen(datas, sizeof(struct test_s));
    cr_assert_eq(result, 2);
    free(datas);
}
