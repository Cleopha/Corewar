/*
** EPITECH PROJECT, 2020
** get_params.c
** File description:
** Coline SEGURET's get_params.c made the 05/15/2020
*/

#include "vm_prototypes.h"

int get_indirect(vm_t *vm, elem_t **champs)
{
    int index_values = (int)retrieve_short(vm->mem, (*champs)->index_actual);

    (*champs)->index_actual += 2;
    return (index_values);
}

int get_direct(vm_t *vm, elem_t **champs, int diff)
{
    int values = 0;

    if (diff) {
        values = retrieve_int(vm->mem, (*champs)->index_actual);
        (*champs)->index_actual += 4;
    } else {
        values = (int)retrieve_short(vm->mem, (*champs)->index_actual);
        (*champs)->index_actual += 2;
    }
    return (values);
}

int get_index_reg(vm_t *vm, elem_t **champs)
{
    int index = (int)vm->mem[(*champs)->index_actual];

    (*champs)->index_actual += 1;
    return (index);
}

void set_param_with_byte(unsigned char coding_byte, unsigned char params[4])
{
    params[0] = coding_byte >> 6;
    params[1] = (coding_byte & 48) >> 4;
    params[2] = (coding_byte & 12) >> 2;
    params[3] = (coding_byte & 3);
}
