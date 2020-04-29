/*
** EPITECH PROJECT, 2019
** C-LIB
** File description:
** malloc with set 0 value
*/


#include "attribute.h"
#include "pointer/allocation.h"

void *my_init_malloc(size_t number, size_t unit)
{
    size_t malloc_size = number * unit + unit;
    byte *result;

    if (malloc_size <= unit)
        return (NULL);
    result = malloc(malloc_size);
    if (!result)
        return (NULL);
    for (size_t i  = 0; i < malloc_size; i++)
        result[i] = 0;
    return (result);
}

void *my_malloc(size_t number, size_t unit)
{
    size_t malloc_size = number * unit + unit;
    byte *result;

    if (malloc_size <= unit)
        return (NULL);
    result = malloc(malloc_size);
    if (!result)
        return (NULL);
    for (size_t i  = malloc_size - unit; i < malloc_size; i++)
        result[i] = 0;
    return (result);
}
