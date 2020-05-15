/*
** EPITECH PROJECT, 2020
** ldi.c
** File description:
** Coline SEGURET's ldi.c made the 05/15/2020
*/

#include "vm_struct.h"
#include "champ_struct.h"

void ldi(vm_t *vm, elem_t *champs)
{
    unsigned char params[4] = {0};
    unsigned char coding_byte = 0;
    int value_one = 0;
    int value_two = 0;
    int ind = 0;

    champs->instruction_cycles = 25;
    champs->index_actuals += 1;
    coding_byte = vm->mem[champs->index_actuals];
    set_param_with_byte(coding_byte, params);
    champs->index_actuals += 1;

    if (param[0] == REG)
        value_one = champs->reg[get_index_reg(vm, champs)];
    else if (param[0] == DIR) {
        value_one = get_direct(vm, champs, DIR_SHORT);
    }
    else if (param[0] == IND) {
        values_one = retrieve_int(vm->mem, champs->pc +
        get_indirect(vm, champs) % IDX_MOD);
    }
    if (param[1] == REG)
        value_two = champs->reg[get_index_reg(vm, champs)];
    else if (param[1] == DIR) {
        value_two = get_direct(vm, champs, DIR_SHORT);
    }
    ind = values_one + values_two;
    champs->reg[get_index_reg(vm, champs)] =
    retrieve_int(vm->mem, champs->pc + ind % IDX_MOD);
    champs->pc = champs->index_actual;
}
