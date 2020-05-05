/*
** EPITECH PROJECT, 2020
** error_management.c
** File description:
** Coline SEGURET's error_management.c made the 04/30/2020
*/

#include "corewar.h"

int loop_check(char **words, unsigned char *param, info_t *info);
size_t loop_fill_bytes(char **bytes, char **words, info_t info);

int malloc_bytes(char **bytes, info_t info, unsigned char param)
{
    (*bytes) = malloc(sizeof(char) * info.byte);
    if (*bytes == NULL)
        return (1);
    (*bytes)[0] = op_tab[info.index_op].code;
    (*bytes)[1] = param;
    return (0);
}

size_t error_management(char **bytes, char **words)
{
    ssize_t hash = strhash(words[0]);
    int index_op = 0;
    unsigned char param = 0;
    info_t info;

    for (; op_tab[index_op].mnemonique; index_op += 1)
        if (op_tab[index_op].hash == hash)
            break;
    if (!op_tab[index_op].mnemonique)
        return (-1);
    info = (info_t) {index_op, 1, 0, 1};
    if (op_tab[index_op].nbr_args != (int)(tablen(words, sizeof(char *)) - 1))
        return (-1);
    if (loop_check(words, &param, &info))
        return (-1);
    for (; info.nb_param < 4; info.nb_param += 1)
        param <<= 2;
    if (malloc_bytes(bytes, info, param))
        return (-1);
    return (loop_fill_bytes(bytes, words, info) + 1);
}
