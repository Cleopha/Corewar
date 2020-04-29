/*
** EPITECH PROJECT, 2019
** C-LIB
** File description:
** tabcat
*/

#include "pointer.h"

void *tabcat(const void *tab1, const void *tab2, size_t unit)
{
    size_t tab1_len = tablen(tab1, unit);
    size_t total = tab1_len + tablen(tab2, unit);
    char *result;

    result = my_malloc(total, unit);
    if (!result)
        return (NULL);
    total *= unit;
    tab1_len *= unit;
    for (size_t i = 0; i < total; i++) {
        if (i < tab1_len)
            result[i] = ((char *) tab1)[i];
        else
            result[i] = ((char *) tab2)[i - tab1_len];
    }
    return (result);
}
