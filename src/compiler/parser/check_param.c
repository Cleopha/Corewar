/*
** EPITECH PROJECT, 2020
** check_param.c
** File description:
** Coline SEGURET's check_param.c made the 04/30/2020
*/

#include "corewar.h"

static int t_reg(char *words, unsigned char *param, info_t *info)
{
    if (tabstart(words, "r", sizeof(char))) {
        info->index_word += 1;
        info->byte += 1;
        *param <<= 1;
        *param <<= 1;
        *param |= 1;
        info->nb_param += 1;
        return (1);
    }
    return (0);
}

static int t_dir(char *words, unsigned char *param, info_t *info)
{
    if (tabstart(words, "%", sizeof(char))) {
        info->index_word += 1;
        info->byte += 4;
        *param <<= 1;
        *param |= 1;
        *param <<= 1;
        info->nb_param += 1;
        return (1);
    }
    return (0);
}

static int t_ind(char *words, unsigned char *param, info_t *info)
{
    info->index_word += 1;
    info->byte += 1;
    *param |= 1;
    *param <<= 1;
    *param |= 1;
    *param <<= 1;
    info->nb_param += 1;
    return (1);
}

static int t_lab(char *words, info_t *info)
{
    if (tabstart(words, "%:", sizeof(char))) {
        info->index_word += 1;
        info->byte += 4;
        info->nb_param += 1;
        return (1);
    }
    return (0);
}

int loop_check(char **words, unsigned char *param, info_t *info)
{
    int tmp = info->index_word;

    for (int y = 0; y < op_tab[info->index_op].nbr_args; y += 1 ) {
        tmp = info->index_word;
        if (op_tab[info->index_op].type[y] & T_REG)
            if (t_reg(words[info->index_word], param, info))
                continue;
        if (op_tab[info->index_op].type[y] & T_DIR)
            if (t_dir(words[info->index_word], param, info))
                continue;
        if (op_tab[info->index_op].type[y] & T_LAB)
            if (t_lab(words[info->index_word], info))
                continue;
        if (op_tab[info->index_op].type[y] & T_IND)
            if (t_ind(words[info->index_word], param, info))
                continue;
        if (tmp == info->index_word)
            return (1);
    }
    return (0);
}
