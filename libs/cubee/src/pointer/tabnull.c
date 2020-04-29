/*
** EPITECH PROJECT, 2019
** C-LIB
** File description:
** tab value is null
*/

#include <unistd.h>

char tab_isnull(const void *tab, size_t unit)
{
    if (!tab || !unit)
        return (1);
    else if (unit == 1)
        return (!((char *) tab)[0]);
    for (size_t i = 0; i < unit; i++)
        if (((char *) tab)[i])
            return (0);
    return (1);
}
