/*
** EPITECH PROJECT, 2019
** C-LIBS
** File description:
** Test my_malloc function
*/

#include "unit_test.h"

Test(clib_pointer_init_malloc, normal_test)
{
    int *result = my_init_malloc(5, sizeof(int));

    cr_assert(result);
    if (!result)
        return;
    for (size_t i = 0; i < 6; i++)
        cr_assert(!result[i]);
    free(result);
}

Test(clib_pointer_init_malloc, malloc_error_test)
{
    char *result;

    malloc_error_test = 1;
    result = my_init_malloc(5, sizeof(int));
    cr_assert(!result);
    cfree(result, NULL);
}

Test(clib_pointer_init_malloc, empty_unit)
{
    char *result = my_init_malloc(11, 0);

    cr_assert(!result);
    if (result)
        free(result);
}

Test(clib_pointer_init_malloc, empty_number)
{
    char *result = my_init_malloc(0, sizeof(char));

    cr_assert(!result);
    if (result)
        free(result);
}
