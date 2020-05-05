/*
** EPITECH PROJECT, 2020
** convert_in_bin.c
** File description:
** Coline SEGURET's convert_in_bin.c made the 05/01/2020
*/

#include "corewar.h"

static int fill_reg(char **bytes, char *words, int *index, info_t *info)
{
    if (tabstart(words, "r", sizeof(char))) {
        (*bytes)[*index] = getnbr(++words);
        *index += 1;
        info->index_word += 1;
        return (1);
    }
    return (0);
}

static int fill_dir(char **bytes, char *words, int *index, info_t *info)
{
    if (tabstart(words, "%", sizeof(char))) {
        *((int *)((*bytes) + *index)) = getnbr(++words);
        *index += 4;
        info->index_word += 1;
        return (1);
    }
    return (0);
}

static int fill_ind(char **bytes, char *words, int *index, info_t *info)
{
    *((int *)((*bytes) + *index)) = getnbr(words + 2);
    *index += 4;
    info->index_word += 1;
    return (1);
}

static int fill_lab(char **bytes, char *words, int *index, info_t *info)
{
    if (tabstart(words, "%:", sizeof(char))) {
        *((int *)((*bytes) + *index)) = getnbr(words + 2);
        *index += 4;
        info->index_word += 1;
        return (1);
    }
    return (0);
}

size_t loop_fill_bytes(char **bytes, char **words, info_t info)
{
    int index = 2;

    info.index_word = 1;
    for (int y = 0; y < op_tab[info.index_op].nbr_args; y += 1 ) {
        if (op_tab[info.index_op].type[y] & T_REG)
            if (fill_reg(bytes, words[info.index_word], &index, &info))
                continue;
        if (op_tab[info.index_op].type[y] & T_DIR)
            if (fill_dir(bytes, words[info.index_word], &index, &info))
                continue;
        if (op_tab[info.index_op].type[y] & T_LAB)
            if (fill_lab(bytes, words[info.index_word], &index, &info))
                continue;
        if (op_tab[info.index_op].type[y] & T_IND)
            if (fill_ind(bytes, words[info.index_word], &index, &info))
                continue;
    }
    return (info.byte);
}
