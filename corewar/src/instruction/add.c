/*
** EPITECH PROJECT, 2020
** add.c
** File description:
** Coline SEGURET's add.c made the 05/15/2020
*/

#include "vm_prototypes.h"

int add(vm_t *vm, elem_t *champs)
{
    int index = 0;
    int values_r1 = 0;
    int values_r2 = 0;

    printf("add\n");
    champs->instruction_cycles = 10;
    champs->index_actual += 2;
    index = get_index_reg(vm, champs);
    values_r1 = champs->reg[index];
    index = get_index_reg(vm, champs);
    values_r2 = champs->reg[index];
    set_carry_flag(values_r1 + values_r2, vm);
    champs->reg[get_index_reg(vm, champs)] = values_r1 + values_r2;
    champs->pc = champs->index_actual;
    return (0);
}
