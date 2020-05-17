/*
** EPITECH PROJECT, 2019
** C-LIB
** File description:
** tabfind units tests
*/

#include "unit_test.h"

struct test_s {
    char data;
    void *random;
};

Test(clib_pointer_tabcount, normal_test)
{
    static const char *data = "Hello World !";
    static const char *search = "l";
    size_t count = tabcount(data, search, sizeof(char));

    cr_assert_eq(count, 3);
}

Test(clib_pointer_tabcount, struct_test)
{
    static const struct test_s data[4] = {{1, 0}, {2, 0}, {2, 0}, {0, 0}};
    static const struct test_s find[2] = {{2, 0}, {0, 0}};
    size_t count = tabcount(data, find, sizeof(struct test_s));

    cr_assert_eq(count, 2);
}

Test(clib_pointer_tabcount, null_data_test)
{
    static const char *search =	"World";
    size_t count = tabcount(NULL, search, sizeof(char));

    cr_assert_eq(count, 0);
}

Test(clib_pointer_tabcount, null_search_test)
{
    static const char *data = "Hello World !";
    size_t count = tabcount(data, NULL, sizeof(char));

    cr_assert_eq(count, 0);
}

Test(clib_pointer_tabcount, null_unit_test)
{
    static const char *data = "Hello World !";
    static const char *search =	"l";
    size_t count = tabcount(data, search, 0);

    cr_assert_eq(count, 0);
}

Test(clib_pointer_tabcount, not_found_test)
{
    static const char *data = "Hello World !";
    static const char *search = "x";
    size_t count = tabcount(data, search, sizeof(char));

    cr_assert_eq(count, 0);
}
