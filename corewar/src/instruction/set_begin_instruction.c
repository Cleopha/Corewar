/*
** EPITECH PROJECT, 2020
** set_begin_instruction.c
** File description:
** Coline SEGURET's set_begin_instruction.c made the 05/16/2020
*/

#include "vm_prototypes.h"

void set_carry_flag(int nb, vm_t *vm)
{
    if (nb == 0)
        vm->carry = 1;
    else
        vm->carry = 0;
}

void set_param_with_byte(unsigned char coding_byte, unsigned char params[4])
{
    params[0] = coding_byte >> 6;
    params[1] = (coding_byte & 48) >> 4;
    params[2] = (coding_byte & 12) >> 2;
    params[3] = (coding_byte & 3);
}

void skip_coding_byte(elem_t *champs, vm_t *vm,
unsigned char params[4], int nb_inst)
{
    unsigned char coding_byte = 0;

    champs->instruction_cycles = nb_inst;
    champs->index_actual += 1;
    coding_byte = vm->mem[champs->index_actual];
    set_param_with_byte(coding_byte, params);
    champs->index_actual += 1;
}
