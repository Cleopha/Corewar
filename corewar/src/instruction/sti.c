/*
** EPITECH PROJECT, 2020
** sti.c
** File description:
** Coline SEGURET's sti.c made the 05/15/2020
*/

#include "vm_prototypes.h"

int sti(vm_t *vm, elem_t *champs)
{
    unsigned char params[4] = {0};
    int value_reg = 0;
    int value_one = 0;
    int value_two = 0;

    printf("sti\n");
    skip_coding_byte(champs, vm, params, 25);
    value_reg = champs->reg[get_index_reg(vm, champs)];
    get_param(params[1], &value_one, vm, champs);
    get_param(params[2], &value_two, vm, champs);
    ind_write(vm, champs, value_reg, value_one + value_two);
    champs->pc = champs->index_actual;
    return (0);
}
