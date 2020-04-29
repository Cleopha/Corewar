/*
** EPITECH PROJECT, 2019
** C-LIB
** File description:
** tab dump
*/

#include "pointer/allocation.h"

void *tabdump(const void *tab, size_t unit)
{
    size_t length = tablen(tab, unit);
    size_t total_len = length * unit;
    char *result;

    if (!length)
        return (NULL);
    result = my_malloc(length, unit);
    if (!result)
        return (NULL);
    for (size_t i = 0; i < total_len; i++)
        result[i] = ((char *) tab)[i];
    return (result);
}
