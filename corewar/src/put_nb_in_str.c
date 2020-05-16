/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** put_nb_in_str.c
*/

#include "union.h"
#include "vm_prototypes.h"

void ind_write(vm_t *vm, elem_t *champs, int value, int ind)
{
    union endian en;

    en.nb = value;
    for (int i = 0; i < 4; i++)
        vm->mem[(champs->pc + ind) % IDX_MOD + i] = en.str[i];
}
