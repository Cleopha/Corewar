/*
** EPITECH PROJECT, 2019
** C-LIBS
** File description:
** Test my_double_free function
*/

#include "unit_test.h"

Test(clib_pointer_multiple_cfree, normal_test)
{
    char **list = my_malloc(2, sizeof(char *));

    cr_assert(list);
    if (!list)
        return;
    for (size_t i = 0; i < 2; i++) {
        list[i] = my_malloc(1, sizeof(char));
        if (!list[i])
            break;
    }
    mcfree((void **) list, 1, NULL);
}

Test(clib_pointer_multiple_cfree, null_value)
{
    char **list = NULL;

    mcfree((void **) list, 1, NULL);
}

Test(clib_pointer_multiple_cfree_function_pointer, null_value)
{
    char **list = NULL;

    mcfree((void **) list, 1, free);
}

Test(clib_pointer_multiple_cfree_function_pointer, normal_test)
{
    char **list = my_malloc(2, sizeof(char *));

    cr_assert(list);
    if (!list)
        return;
    for (size_t i = 0; i < 2; i++) {
        list[i] = my_malloc(1, sizeof(char));
        if (!list[i])
            break;
    }
    mcfree((void **) list, 1, free);
}

Test(clib_pointer_multiple_cfree_function_pointer, one_level)
{
    char *array = my_malloc(5, sizeof(char));

    cr_assert(array);
    if (!array)
        return;
    mcfree((void **) array, 0, free);
}
