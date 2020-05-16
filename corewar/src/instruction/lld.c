/*
** EPITECH PROJECT, 2020
** lld.c
** File description:
** Coline SEGURET's lld.c made the 05/15/2020
*/

#include "vm_prototypes.h"

void lld(vm_t *vm, elem_t **champs)
{
    unsigned char params[4] = {0};
    unsigned char coding_byte = 0;
    int value = 0;

    (*champs)->instruction_cycles = 10;
    (*champs)->index_actual += 1;
    coding_byte = vm->mem[(*champs)->index_actual];
    set_param_with_byte(coding_byte, params);
    (*champs)->index_actual += 1;

    if (params[0] == DIR)
        value = get_direct(vm, champs, DIR_INT);
    else if (params[0] == IND)
        value = retrieve_int(vm->mem, (*champs)->pc +
        get_indirect(vm, champs));
    (*champs)->reg[get_index_reg(vm, champs)] = value;
    (*champs)->pc = (*champs)->index_actual;
}
