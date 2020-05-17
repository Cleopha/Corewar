/*
** EPITECH PROJECT, 2020
** CoreWar
** File description:
** my atoi function
*/

#include "corewar_util.h"

int my_atoi(char const *str)
{
    int sign = 1;
    int result = 0;

    if (!str)
        return (0);
    for (; *str && (*str < '0' || *str > '9') && *str != '-' && *str != '+';
        str++);
    if (*str == '+')
        ++str;
    if (*str == '-') {
        sign = -1;
        ++str;
    }
    for (size_t i = 0; str[i]; i++) {
        result = (result << 3) + (result << 1);
        result += (str[i] - 48);
    }
    return (result* sign);
}