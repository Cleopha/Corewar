/*
** EPITECH PROJECT, 2020
** ld.c
** File description:
** Coline SEGURET's ld.c made the 05/15/2020
*/

#include "vm_struct.h"
#include "champ_struct.h"

void ld(vm_t *vm, elem_t *champs)
{
    unsigned char params[4] = {0};
    unsigned char coding_byte = 0;
    int value = 0;

    champs->instruction_cycles = 5;
    champs->index_actuals += 1;
    coding_byte = vm->mem[champs->index_actuals];
    set_param_with_byte(coding_byte, params);
    champs->index_actuals += 1;

    if (param[0] == DIR)
        value = get_direct(vm, champs, DIR_INT);
    else if (param[0] == IND)
        values = retrieve_int(vm->mem, champs->pc +
        get_indirect(vm, champs) % IDX_MOD);
    champs->reg[get_index_reg(vm, champs)] = values;
    champs->pc = champs->index_actual;
}
