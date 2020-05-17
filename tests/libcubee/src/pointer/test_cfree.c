/*
** EPITECH PROJECT, 2019
** C-LIBS
** File description:
** Test cfree function
*/

#include "unit_test.h"

Test(clib_pointer_cfree, normal_test)
{
    void *allocation = my_malloc(1, sizeof(char));

    cfree(allocation, NULL);
    cr_assert(allocation);
}

Test(clib_pointer_cfree, normal_test_function_pointer)
{
    void *allocation = my_malloc(1, sizeof(char));

    cfree(allocation, free);
    cr_assert(allocation);
}

Test(clib_pointer_cfree, null_value)
{
    cfree(NULL, NULL);
    cr_assert(1);
}
