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
    unsigned char param[4] = {0};

    printf("lfork\n");
    champs->index_actual += 1;
    champs->instruction_cycles = 1000;
    set_param_with_byte(vm->mem[champs->index_actual], param);
    if (param[0] == IND)
        node->address = champs->pc + get_indirect(vm, champs);
    if (node->address > MEM_SIZE || node->address < 0)
        return (1);
    init_forked_prog(champs, node);
    for (int i = 0; i < node->header.prog_size; i++)
        vm->mem[node->address + i] = vm->mem[champs->address + i];
    return (0);
}
