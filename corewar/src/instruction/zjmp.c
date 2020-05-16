/*
** EPITECH PROJECT, 2020
** zjmp.c
** File description:
** Coline SEGURET's zjmp.c made the 05/15/2020
*/

#include "vm_prototypes.h"

void zjmp(vm_t *vm, elem_t **champs)
{
    (*champs)->instruction_cycles = 20;
    (*champs)->index_actual += 1;
    if (vm->carry) {
        (*champs)->index_actual = (*champs)->pc +
        get_direct(vm, champs, DIR_SHORT) % IDX_MOD;
    }
    (*champs)->pc = (*champs)->index_actual;
}
