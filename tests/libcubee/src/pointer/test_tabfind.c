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

Test(clib_pointer_tabfind, normal_test)
{
    static const char *data = "Hello World !";
    static const char *search = "World";
    char *ptr = tabfindptr(data, search, sizeof(char));
    ssize_t pos = tabfind(data, search, sizeof(char));

    cr_assert_eq(pos, 6);
    cr_assert_str_eq(ptr, "World !");
}

Test(clib_pointer_tabfind, struct_test)
{
    static const struct test_s data[4] = {{1, 0}, {2, 0}, {3, 0}, {0, 0}};
    static const struct test_s find[2] = {{2, 0}, {0, 0}};
    struct test_s *ptr = tabfindptr(data, find, sizeof(struct test_s));
    ssize_t pos = tabfind(data, find, sizeof(struct test_s));

    cr_assert_eq(pos, 1);
    cr_assert_eq((*(ptr + 1)).data, 3);
}

Test(clib_pointer_tabfind, null_data_test)
{
    static const char *search = "World";
    char *ptr = tabfindptr(NULL, search, sizeof(char));
    ssize_t pos = tabfind(NULL, search, sizeof(char));

    cr_assert_eq(pos, -1);
    cr_assert(!ptr);
}

Test(clib_pointer_tabfind, null_search_test)
{
    static const char *data = "Hello World !";
    char *ptr = tabfindptr(data, NULL, sizeof(char));
    ssize_t pos = tabfind(data, NULL, sizeof(char));

    cr_assert_eq(pos, -1);
    cr_assert(!ptr);
}

Test(clib_pointer_tabfind, null_unit_test)
{
    static const char *data = "Hello World !";
    static const char *search = "World";
    char *ptr = tabfindptr(data, search, 0);
    ssize_t pos = tabfind(data, search, 0);

    cr_assert_eq(pos, -1);
    cr_assert(!ptr);
}

Test(clib_pointer_tabfind, not_found_test)
{
    static const char *data = "Hello World !";
    static const char *search = "Toto";
    char *ptr = tabfindptr(data, search, sizeof(char));
    ssize_t pos = tabfind(data, search, sizeof(char));

    cr_assert_eq(pos, -1);
    cr_assert(!ptr);
}
