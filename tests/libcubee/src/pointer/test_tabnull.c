/*
** EPITECH PROJECT, 2019
** C-LIB
** File description:
** tabdump units tests
*/

#include "unit_test.h"

struct test_s {
    char value;
    void *random;
};

Test(clib_pointer_tabnull, normal_test)
{
    static const char *data = "Hello World !";

    cr_assert_eq(tab_isnull(data + 13, sizeof(char)), 1);
    cr_assert_eq(tab_isnull(data + 12, sizeof(char)), 0);
}

Test(clib_pointer_tabnull, normal_struct_test)
{
    struct test_s *sdata = my_malloc(2, sizeof(struct test_s));

    cr_assert(sdata);
    if (!sdata)
        return;
    sdata[0].value = '1';
    sdata[1].value = '2';
    cr_assert_eq(tab_isnull(&sdata[0],
        sizeof(struct test_s)), 0);
    cr_assert_eq(tab_isnull(&sdata[1],
        sizeof(struct test_s)), 0);
    cr_assert_eq(tab_isnull(&sdata[2],
        sizeof(struct test_s)), 1);
}

Test(clib_pointer_tabnull, null_str_test)
{
    cr_assert_eq(tab_isnull(NULL, sizeof(char)), 1);
}

Test(clib_pointer_tabnull, null_unit_size_test)
{
    static const char *data = "Hello World !";

    cr_assert_eq(tab_isnull(data + 12, 0), 1);
}
