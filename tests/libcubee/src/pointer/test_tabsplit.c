/*
** EPITECH PROJECT, 2019
** C-LIB
** File description:
** tabspli units tests
*/

#include "unit_test.h"

struct test_s {
    char data;
    void *random;
};

static void free_tab(void **table, size_t size)
{
    if (!table)
        return;
    for (size_t i = 0; i < size; i++) {
        cfree(table[i], NULL);
    }
    free(table);
}

Test(clib_pointer_tabsplit, normal_test)
{
    static const char *data = "Hello  World !";
    size_t size = 0;
    char **result = (char **) tabsplit(data, " ", sizeof(char), &size);

    cr_assert_eq(size, 4);
    cr_assert(result);
    if (!result)
        return;
    cr_assert_str_eq(result[0], "Hello");
    cr_assert(!result[1]);
    cr_assert_str_eq(result[2], "World");
    cr_assert_str_eq(result[3], "!");
    free_tab((void **) result, size);
}

Test(clib_pointer_tabsplit_clean, normal_test)
{
    static const char *data = "   Hello  World !  ";
    char **result = (char **) tabsplit_clean(data, " ", sizeof(char));

    cr_assert(result);
    if (!result)
        return;
    cr_assert_str_eq(result[0], "Hello");
    cr_assert_str_eq(result[1], "World");
    cr_assert_str_eq(result[2], "!");
    cr_assert(!result[3]);
    mcfree(result, 1, NULL);
}

Test(clib_pointer_tabsplit, normal_struct_test)
{
    static const struct test_s data[6] = {{1, 0}, {2, 0}, {254, (void *) 254},
        {3, 0}, {4, 0}, {0, 0}};
    static const struct test_s split[2] = {{254, (void *) 254}, {0, 0}};
    size_t size = 0;
    struct test_s  **result = (struct test_s **) tabsplit(data, split,
        sizeof(struct test_s), &size);

    cr_assert_eq(size, 2);
    cr_assert(result);
    if (!result)
        return;
    for (size_t i = 0; i < 4; i++) {
        cr_assert_eq(result[i / 2][i - (2 * (i / 2))].data, (char) (i + 1));
        cr_assert_eq(result[i / 2][i - (2 * (i / 2))].random, 0);
    }
    free_tab((void **) result, size);
}

Test(clib_pointer_tabsplit, null_data_test)
{
    size_t size = 0;
    char **result = (char **) tabsplit(NULL, " ", sizeof(char), &size);

    cr_assert_eq(size, 0);
    cr_assert(!result);
    free_tab((void **) result, size);
}

Test(clib_pointer_tabsplit, null_search_test)
{
    static const char *data = "Hello World !";
    size_t size = 0;
    char **result = (char **) tabsplit(data, NULL, sizeof(char), &size);

    cr_assert_eq(size, 0);
    cr_assert(!result);
    free_tab((void **) result, size);
}

Test(clib_pointer_tabsplit, null_unit_size_test)
{
    static const char *data = "Hello World !";
    size_t size = 0;
    char **result = (char **) tabsplit(data, " ", 0, &size);

    cr_assert_eq(size, 0);
    cr_assert(!result);
    free_tab((void **) result, size);
}

Test(clib_pointer_tabsplit, null_size_test)
{
    static const char *data = "Hello World !";
    char **result = (char **) tabsplit(data, " ", sizeof(char), NULL);

    cr_assert(!result);
}

Test(clib_pointer_tabsplit, not_found_split_test)
{
    static const char *data = "Hello World !";
    size_t size = 0;
    char **result = (char **) tabsplit(data, "{}", sizeof(char), &size);

    cr_assert_eq(size, 1);
    cr_assert_str_eq(result[0], data);
    free_tab((void **) result, size);
}

Test(clib_pointer_tabsplit, error_malloc_1)
{
    static const char *data = "Hello  World !";
    size_t size = 0;
    char **result;

    malloc_error_test = 1;
    result = (char **) tabsplit(data, " ", sizeof(char), &size);
    cr_assert_eq(size, 0);
    cr_assert(!result);
    free_tab((void **) result, size);
}

Test(clib_pointer_tabsplit, error_malloc_2)
{
    static const char *data = "Hello World !";
    size_t size = 0;
    char **result;

    malloc_error_test = -2;
    result = (char **) tabsplit(data, " ", sizeof(char), &size);
    cr_assert_eq(size, 3);
    cr_assert(!result[0]);
    cr_assert_str_eq(result[1], "World");
    cr_assert_str_eq(result[2], "!");
    free_tab((void **) result, size);
}

Test(clib_pointer_tabsplit_clean, error_malloc)
{
    static const char *data = "Hello World !";
    char **result;

    malloc_error_test = 1;
    result = (char **) tabsplit_clean(data, " ", sizeof(char));
    cr_assert(!result);
    mcfree(result, 1, NULL);
}
