/*
** EPITECH PROJECT, 2020
** or.c
** File description:
** Coline SEGURET's or.c made the 05/15/2020
*/

#include "vm_prototypes.h"

int or(vm_t *vm, elem_t *champs)
{
    unsigned char params[4] = {0};
    int value_one = 0;
    int value_two = 0;

    printf("or\n");
    skip_coding_byte(champs, vm, params, 6);
    get_param(params[0], &value_one, vm, champs);
    get_param(params[1], &value_two, vm, champs);
    set_carry_flag(value_one | value_two, vm);
    champs->reg[get_index_reg(vm, champs)] = value_one | value_two;
    champs->pc = champs->index_actual;
    return (0);
}
