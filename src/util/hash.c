/*
** EPITECH PROJECT, 2020
** CoreWar
** File description:
** hash functions
*/

#include "corewar_util.h"

ssize_t hash(const char *str)
{
    size_t result = 0;

    if (!str)
        return (result);
    for (size_t i = 0; str[i]; i++)
        result = 31 * result + str[i];
    return (result);
}
