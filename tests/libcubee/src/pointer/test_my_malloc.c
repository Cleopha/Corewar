/*
** EPITECH PROJECT, 2019
** C-LIBS
** File description:
** Test my_malloc function
*/

#include "unit_test.h"

Test(clib_pointer_malloc, normal_test)
{
    int *result = my_malloc(5, sizeof(int));

    cr_assert(result);
    if (!result)
        return;
    cr_assert(!result[5]);
    free(result);
}

Test(clib_pointer_malloc, malloc_error_test)
{
    int *result;

    malloc_error_test = 1;
    result = my_malloc(5, sizeof(char));
    cr_assert(!result);
    cfree(result, NULL);
}

Test(clib_pointer_malloc, empty_unit)
{
    char *result = my_malloc(11, 0);

    cr_assert(!result);
    cfree(result, NULL);
}

Test(clib_pointer_malloc, empty_number)
{
    char *result = my_malloc(0, sizeof(char));

    cr_assert(!result);
    cfree(result, NULL);
}
