/*
** EPITECH PROJECT, 2020
** sub.c
** File description:
** Coline SEGURET's sub.c made the 05/15/2020
*/

#include "vm_prototypes.h"
#include "champ_struct.h"

void sub(vm_t *vm, elem_t *champs)
{
    int index = 0;
    int values_r1 = 0;
    int values_r2 = 0;

    champs->instruction_cycles = 10;
    champs->index_actual += 2;
    index = get_index_reg(vm, champs);
    values_r1 = champs->reg[index];
    index = get_index_reg(vm, champs);
    values_r2 = champs->reg[index];
    champs->reg[get_index_reg(vm, champs)] = values_r1 - values_r2;
    champs->pc = champs->index_actual;
}
