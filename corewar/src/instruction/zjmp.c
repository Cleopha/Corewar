/*
** EPITECH PROJECT, 2020
** zjmp.c
** File description:
** Coline SEGURET's zjmp.c made the 05/15/2020
*/

#include "vm_prototypes.h"

int zjmp(vm_t *vm, elem_t *champs)
{
    champs->instruction_cycles = 20;
    champs->index_actual += 1;
    if (champs->carry) {
        champs->index_actual = (champs->pc +
        get_direct(vm, champs, DIR_SHORT)) % IDX_MOD;
    } else
        champs->index_actual += 2;
    champs->pc = champs->index_actual;
    return (0);
}
