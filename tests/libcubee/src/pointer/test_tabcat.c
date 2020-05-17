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

Test(clib_pointer_tabcat, normal_test)
{
    char *result = tabcat("Hello", " World !", sizeof(char));

    cr_assert_str_eq(result, "Hello World !");
    cfree(result, NULL);
}

Test(clib_pointer_tabcat, normal_struct_test)
{
    static const struct test_s data1[3] = {{1, NULL}, {2, NULL}, {0, NULL}};
    static const struct test_s data2[3] = {{3, NULL}, {4, NULL}, {0, NULL}};
    struct test_s *result = tabcat(data1, data2, sizeof(struct test_s));

    for (size_t i = 0; i < 4; i++) {
        cr_assert_eq(result[i].data, (char) (i + 1));
        cr_assert(!result[i].random);
    }
    cfree(result, NULL);
}

Test(clib_pointer_tabcat, null_str_test)
{
    char *result = tabcat(NULL, " World !", sizeof(char));

    cr_assert_str_eq(result, " World !");
    cfree(result, NULL);
}

Test(clib_pointer_tabcat, null_str_test_2)
{
    char *result = tabcat("World", NULL, sizeof(char));

    cr_assert_str_eq(result, "World");
    cfree(result, NULL);
}

Test(clib_pointer_tabcat, null_unit_size_test)
{
    char *result = tabcat("Hello", " World !", 0);

    cr_assert(!result);
    cfree(result, NULL);
}

Test(clib_pointer_tabcat, malloc_error_test)
{
    char *result;

    malloc_error_test = 1;
    result = tabcat("Hello", " World !", sizeof(char));
    cr_assert(!result);
    cfree(result, NULL);
}
