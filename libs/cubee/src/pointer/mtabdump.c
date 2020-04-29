/*
** EPITECH PROJECT, 2019
** C-LIB
** File description:
** tab dump
*/

#include "pointer/allocation.h"
#include "pointer.h"

void *mtabdump(const void *tab, size_t unit, size_t level)
{
    void **result;

    if (!level || !tab || !unit)
        return (NULL);
    result = tabdump(tab, (level > 1) ? sizeof(void *) : unit);
    if (!result || level < 2)
        return (result);
    for (size_t i = 0; ((void **) tab)[i]; i++)
        result[i] = mtabdump(((void **) tab)[i], unit, level - 1);
    return (result);
}
