/*
** EPITECH PROJECT, 2019
** C-LIB
** File description:
** get tab size
*/

#include "pointer/allocation.h"

static int is_null(const byte *bytes, size_t index, size_t unit)
{
    for (size_t i = 0; i < unit; i++)
        if (bytes[index + i])
            return (0);
    return (1);
}

size_t tablen(const void *element, size_t unit)
{
    size_t result = 0;

    if (!element || !unit)
        return (0);
    if (unit == 1)
        for (; ((byte *) element)[result]; result++);
    else
        for (; !is_null((byte *) element, result * unit, unit); result++);
    return (result);
}
