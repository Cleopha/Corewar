/*
** EPITECH PROJECT, 2019
** C-LIB
** File description:
** tabcount
*/

#include "pointer.h"

static int is_null(const char *bytes, size_t index, size_t unit)
{
    for (size_t i = 0; i < unit; i++)
        if (bytes[index + i])
            return (0);
    return (1);
}

size_t tabcount(const void *tab, const void *search, size_t unit)
{
    size_t count = 0;

    if (!tab || !search || !unit)
        return (0);
    for (size_t i = 0; !is_null(tab, i, unit); i += unit)
        if (tabstart(tab + i, search, unit))
            count++;
    return (count);
}
