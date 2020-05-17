/*
** EPITECH PROJECT, 2020
** get_params.c
** File description:
** Coline SEGURET's get_params.c made the 05/15/2020
*/

#include "vm_prototypes.h"

int get_indirect(vm_t *vm, elem_t *champs)
{
    int index_values = (int)retrieve_short(vm->mem, champs->index_actual);
    champs->index_actual += 2;
    return (index_values);
}

int get_direct(vm_t *vm, elem_t *champs, int diff)
{
    int values = 0;
    if (diff) {
        values = retrieve_int(vm->mem, champs->index_actual);
        champs->index_actual += 4;
    } else {
        values = (int)retrieve_short(vm->mem, champs->index_actual);
        champs->index_actual += 2;
    }
    return (values);
}

int get_index_reg(vm_t *vm, elem_t *champs)
{
    int index = (int)vm->mem[champs->index_actual];
    champs->index_actual += 1;
    return (index);
}

void get_param(unsigned char params, int *value_one,
vm_t *vm, elem_t *champs)
{
    unsigned char inst = vm->mem[champs->pc];

    if (params == REG)
        *value_one = champs->reg[get_index_reg(vm, champs)];
    else if (params == DIR) {
        if (inst == 1 || inst == 2 || inst == 6 || inst == 7 || inst == 8)
            *value_one = get_direct(vm, champs, DIR_INT);
        else
            *value_one = get_direct(vm, champs, DIR_SHORT);
    }
    if (params == IND) {
        *value_one = retrieve_int(vm->mem, (champs->pc +
        get_indirect(vm, champs)) % IDX_MOD);
    }
}

void get_param_without_mod(unsigned char params, int *value_one,
                            vm_t *vm, elem_t *champs)
{
    unsigned char inst = vm->mem[champs->pc];

    if (params == REG)
        *value_one = champs->reg[get_index_reg(vm, champs)];
    else if (params == DIR) {
        if (inst == 1 || inst == 2 || inst == 6 || inst == 7 || inst == 8)
            *value_one = get_direct(vm, champs, DIR_INT);
        else
            *value_one = get_direct(vm, champs, DIR_SHORT);
    }
    if (params == IND) {
            *value_one = retrieve_int(vm->mem, champs->pc +
            get_indirect(vm, champs));
    }
}
