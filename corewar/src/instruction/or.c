/*
** EPITECH PROJECT, 2020
** or.c
** File description:
** Coline SEGURET's or.c made the 05/15/2020
*/

#include "vm_prototypes.h"
#include "champ_struct.h"

void or(vm_t *vm, elem_t **champs)
{
    unsigned char params[4] = {0};
    unsigned char coding_byte = 0;
    int value_one = 0;
    int value_two = 0;

    (*champs)->instruction_cycles = 6;
    (*champs)->index_actual += 1;
    coding_byte = vm->mem[(*champs)->index_actual];
    set_param_with_byte(coding_byte, params);
    (*champs)->index_actual += 1;

    if (params[0] == REG)
        value_one = (*champs)->reg[get_index_reg(vm, champs)];
    else if (params[0] == DIR) {
        value_one = get_direct(vm, champs, DIR_INT);
    }
    else if (params[0] == IND) {
        value_one = retrieve_int(vm->mem, (*champs)->pc +
        get_indirect(vm, champs) % IDX_MOD);
    }
    if (params[1] == REG)
        value_two = (*champs)->reg[get_index_reg(vm, champs)];
    else if (params[1] == DIR) {
        value_two = get_direct(vm, champs, DIR_INT);
    }
    else if (params[1] == IND) {
        value_two = retrieve_int(vm->mem, (*champs)->pc +
        get_indirect(vm, champs) % IDX_MOD);
    }
    (*champs)->reg[get_index_reg(vm, champs)] = value_one | value_two;
    (*champs)->pc = (*champs)->index_actual;
}
