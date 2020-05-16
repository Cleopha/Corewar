/*
** EPITECH PROJECT, 2020
** lldi.c
** File description:
** Coline SEGURET's lldi.c made the 05/15/2020
*/

#include "vm_prototypes.h"

void lldi(vm_t *vm, elem_t **champs)
{
    unsigned char params[4] = {0};
    int value_one = 0;
    int value_two = 0;
    int ind = 0;

    skip_coding_byte(champs, vm, params, 50);
    get_param_without_mod(params[0], &value_one, vm, champs);
    get_param_without_mod(params[1], &value_two, vm, champs);
    ind = value_one + value_two;
    set_carry_flag(ind, vm);
    (*champs)->reg[get_index_reg(vm, champs)] =
    retrieve_int(vm->mem, (*champs)->pc + ind);
    (*champs)->pc = (*champs)->index_actual;
}
