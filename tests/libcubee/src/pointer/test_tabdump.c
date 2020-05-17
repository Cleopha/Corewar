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

Test(clib_pointer_tabdump, normal_test)
{
    static const char *str = "Hello World !";
    char *result = tabdump(str, sizeof(char));

    cr_assert_str_eq(result, str);
    cfree(result, NULL);
}

Test(clib_pointer_tabdump, normal_struct_test)
{
    static const struct test_s data[4] = {{1, NULL}, {2, NULL}, {3, NULL},
        {0, NULL}};
    struct test_s *result = tabdump(data, sizeof(struct test_s));

    for (size_t i = 0; i < 3; i++) {
        cr_assert_eq(result[i].data, (char) (i + 1));
        cr_assert(!result[i].random);
    }
    cfree(result, NULL);
}

Test(clib_pointer_tabdump, null_str_test)
{
    char *result = tabdump(NULL, sizeof(char));

    cr_assert(!result);
    cfree(result, NULL);
}

Test(clib_pointer_tabdump, null_unit_size_test)
{
    static const char *str = "Hello World !";
    char *result = tabdump(str, 0);

    cr_assert(!result);
    cfree(result, NULL);
}

Test(clib_pointer_tabdump, malloc_error_test)
{
    static const char *str = "Hello World !";
    char *result;

    malloc_error_test = 1;
    result = tabdump(str, sizeof(char));
    cr_assert(!result);
    cfree(result, NULL);
}
