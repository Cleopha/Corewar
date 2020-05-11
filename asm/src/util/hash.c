/*
** EPITECH PROJECT, 2020
** CoreWar
** File description:
** strhash functions
*/

#include "corewar_util.h"

size_t strhash(const char *str)
{
    size_t result = 0;

    if (!str)
        return (result);
    for (size_t i = 0; str[i]; i++)
        result = 31 * result + str[i];
    return (result);
}
