/*
** EPITECH PROJECT, 2019
** C-LIB
** File description:
** find
*/

#include "pointer.h"

static int is_null(const char *bytes, size_t index, size_t unit)
{
    for (size_t i = 0; i < unit; i++)
        if (bytes[index + i])
            return (0);
    return (1);
}

void *tabfindptr(const void *tab, const void *search, size_t unit)
{
    size_t ptr = (size_t) tab;

    if (!tab || !search || !unit)
        return (NULL);
    for (size_t i = 0; !is_null(tab, i, unit); i += unit)
        if (tabstart(tab + i, search, unit))
            return (((void *) ptr) + i);
    return (NULL);
}

ssize_t tabfind(const void *tab, const void *search, size_t unit)
{
    if (!tab || !search || !unit)
        return (-1);
    for (size_t i = 0; !is_null(tab, i, unit); i += unit)
        if (tabstart(tab + i, search, unit))
            return (i / unit);
    return (-1);
}
