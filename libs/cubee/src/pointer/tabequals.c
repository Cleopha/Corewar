/*
** EPITECH PROJECT, 2019
** C-LIB
** File description:
** tab start width
*/

#include "pointer.h"

static int equals(const char *tab_element, const char *start_element,
    size_t unit)
{
    for (size_t i = 0; i < unit; i++)
        if (tab_element[i] != start_element[i])
            return (0);
    return (1);
}

int tabstart(const void *tab, const void *start, size_t unit)
{
    size_t tab_len = tablen(tab, unit);
    size_t start_len = tablen(start, unit);

    if (!tab || !start || !unit || tab_len < start_len)
        return (0);
    for (size_t i = 0; i < start_len; i++)
        if (!equals(tab + (i * unit), start + (i * unit), unit))
            return (0);
    return (1);
}

int tabend(const void *tab, const void *end, size_t unit)
{
    size_t tab_len = tablen(tab, unit);
    size_t end_len = tablen(end, unit);

    if (!tab || !end || !unit || tab_len < end_len)
        return (0);
    for (size_t i = 0; i < end_len; i++)
        if (!equals(tab + ((tab_len - end_len + i) * unit), end + (i * unit),
            unit))
            return (0);
    return (1);
}

int tabequals(const void *tab1, const void *tab2, size_t unit)
{
    size_t tab1_len = tablen(tab1, unit);
    size_t tab2_len = tablen(tab2, unit);

    if (!tab1_len || !tab2_len || tab1_len != tab2_len)
        return (0);
    tab1_len *= unit;
    for (size_t i = 0; i < tab1_len; i++)
        if (((char *) tab1)[i] != ((char *) tab2)[i])
            return (0);
    return (1);
}
