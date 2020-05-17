/*
** EPITECH PROJECT, 2020
** lfork.c
** File description:
** Coline SEGURET's lfork.c made the 05/15/2020
*/

#include <stdlib.h>
#include "vm_prototypes.h"

int lfork(vm_t *vm, elem_t *champs)
{
    elem_t *node = malloc(sizeof(elem_t));

    champs->index_actual += 1;
    champs->instruction_cycles = 1000;
    node->address = champs->pc + get_indirect(vm, champs);
    if (node->address > MEM_SIZE || node->address < 0)
        return (1);
    init_forked_prog(champs, node);
    champs->pc = champs->index_actual;
    return (0);
}
