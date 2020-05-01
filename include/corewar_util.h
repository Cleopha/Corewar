/*
** EPITECH PROJECT, 2020
** CoreWar
** File description:
** util header
*/

#ifndef _COREWAR_UTIL_H_
#define _COREWAR_UTIL_H_

#include <unistd.h>

typedef struct info_s
{
    int index_op;
    int index_word;
    int nb_param;
    int byte;
}info_t;

ssize_t strhash(const char *str);

#endif
