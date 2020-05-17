/*
** EPITECH PROJECT, 2020
** st.c
** File description:
** Coline SEGURET's st.c made the 05/15/2020
*/

#include "vm_prototypes.h"

int st(vm_t *vm, elem_t *champs)
{
    unsigned char params[4] = {0};
    int value = 0;

    skip_coding_byte(champs, vm, params, 5);
    get_param(params[0], &value, vm, champs);
    if (params[1] == REG)
        champs->reg[get_index_reg(vm, champs)] = value;
    else if (params[1] == IND)
        ind_write(vm, champs, value, get_indirect(vm, champs));
    champs->pc = champs->index_actual;
    return (0);
}
