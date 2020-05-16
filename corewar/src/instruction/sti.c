/*
** EPITECH PROJECT, 2020
** sti.c
** File description:
** Coline SEGURET's sti.c made the 05/15/2020
*/

#include "vm_prototypes.h"

void sti(vm_t *vm, elem_t **champs)
{
    unsigned char params[4] = {0};
    int value_reg = 0;
    int value_one = 0;
    int value_two = 0;
    int ind = 0;

    skip_coding_byte(champs, vm, params, 25);
    value_reg = (*champs)->reg[get_index_reg(vm, champs)];
    if (params[1] == REG)
        value_one = (*champs)->reg[get_index_reg(vm, champs)];
    else if (params[1] == DIR)
        value_one = get_direct(vm, champs, DIR_SHORT);
    else if (params[1] == IND) {
        value_one = retrieve_int(vm->mem, (*champs)->pc +
        get_indirect(vm, champs) % IDX_MOD);
    }
    if (params[2] == REG)
        value_two = (*champs)->reg[get_index_reg(vm, champs)];
    else if (params[2] == DIR)
        value_two = get_direct(vm, champs, DIR_SHORT);
    ind_write(vm, *champs, value_reg, value_one + value_two);
    (*champs)->pc = (*champs)->index_actual;
}
