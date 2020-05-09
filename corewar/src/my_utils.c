/*
** EPITECH PROJECT, 2020
** my_utils.c
** File description:
** Coline SEGURET's my_utils.c made the 05/09/2020
*/

#include "corewar.h"

int is_num(char *str)
{
    for (int i = 0; str[i]; i += 1)
        if (!('0' <= str[i] && str[i] <= '9'))
            return (1);
    return (0);
}

int display_error(char *str)
{
    my_putstr_error(str);
    return (1);
}

void attribute_prognumber(param_t *param)
{
    for (int i = 0; i < 4; i += 1)
        if (!param->prog[i]) {
            param->values[PROGNUMBER] = i + 1;
            param->prog[i] = true;
            break;
        }
}

void create_param(param_t *param)
{
    param->values[PROGNUMBER] = 0;
    param->values[ADDRESS] = -1;
    param->values[DUMP] = 0;
    for (int i = 0; i < 4; i += 1)
        param->prog[i] = false;
}
