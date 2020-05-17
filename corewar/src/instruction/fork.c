/*
** EPITECH PROJECT, 2020
** fork.c
** File description:
** Coline SEGURET's fork.c made the 05/15/2020
*/

#include <stdlib.h>
#include "vm_prototypes.h"

void link_new_node(elem_t *champs, elem_t *node)
{
    for (; champs->next; champs = champs->next);
    champs->next = node;
    champs->next->prev = champs;
}

void init_forked_prog(elem_t *champs, elem_t *node)
{
    node->instruction_cycles = champs->instruction_cycles;
    for (int i = 0; i < 16; i++)
        node->reg[i] = champs->reg[i];
    node->prog_number = champs->prog_number;
    node->fd = champs->fd;
    node->is_alive = champs->is_alive;
    node->index_actual = node->address;
    node->pc = node->address;
    node->header = champs->header;
    node->next = NULL;
    link_new_node(champs, node);
}

int my_fork(vm_t *vm, elem_t *champs)
{
    elem_t *node = malloc(sizeof(elem_t));

    printf("fork\n");
    champs->index_actual += 1;
    champs->instruction_cycles = 800;
    node->address = (champs->pc + get_indirect(vm, champs)) % IDX_MOD;
    if (node->address > MEM_SIZE || node->address < 0)
        return (1);
    init_forked_prog(champs, node);
    for (int i = 0; i < node->header.prog_size; i++)
        vm->mem[node->address + i] = vm->mem[champs->address + i];
    champs->pc = champs->index_actual;
    return (0);
}
