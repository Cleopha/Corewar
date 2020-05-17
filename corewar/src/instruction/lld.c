/*
** EPITECH PROJECT, 2020
** lld.c
** File description:
** Coline SEGURET's lld.c made the 05/15/2020
*/

#include "vm_prototypes.h"

int lld(vm_t *vm, elem_t *champs)
{
    unsigned char params[4] = {0};
    int value = 0;

    printf("lld\n");
    skip_coding_byte(champs, vm, params, 10);
    get_param_without_mod(params[0], &value, vm, champs);
    set_carry_flag(value, vm);
    champs->reg[get_index_reg(vm, champs)] = value;
    champs->pc = champs->index_actual;
    return (0);
}
