/*
** EPITECH PROJECT, 2020
** fork.c
** File description:
** Coline SEGURET's fork.c made the 05/15/2020
*/

#include <stdlib.h>
#include "vm_prototypes.h"

void link_new_node(elem_t **champs, elem_t **node)
{
    if (!(*champs)->next) {
        (*champs)->next = *node;
        (*node)->prev = *champs;
        (*node)->next = NULL;
    } else if (!(*champs)->prev) {
        (*champs)->prev = *node;
        (*node)->next = *champs;
        (*node)->prev = NULL;
    } else {
        (*champs)->next->prev = *node;
        (*node)->next = (*champs)->next;
        (*champs)->next = *node;
        (*node)->prev = (*champs);
    }
}

void init_forked_prog(elem_t **champs, elem_t **node)
{
    (*node)->instruction_cycles = (*champs)->instruction_cycles;
    for (int i = 0; i < 16; i++)
        (*node)->reg[i] = (*champs)->reg[i];
    (*node)->prog_number = (*champs)->prog_number;
    (*node)->fd = (*champs)->fd;
    (*node)->is_alive = (*champs)->is_alive;
    (*node)->index_actual = (*node)->address;
    (*node)->pc = (*node)->address;
    (*node)->header = (*champs)->header;
    link_new_node(champs, node);
}

int my_fork(vm_t *vm, elem_t **champs)
{
    elem_t *node = malloc(sizeof(elem_t));
    unsigned char param[4] = {0};

    (*champs)->index_actual += 1;
    set_param_with_byte(vm->mem[(*champs)->index_actual], param);
    if (param[0] == IND)
        node->address = ((*champs)->pc + get_indirect(vm, champs)) % IDX_MOD;
    if (node->address > MEM_SIZE || node->address < 0)
        return (1);
    init_forked_prog(champs, &node);
    for (int i = 0; i < node->header.prog_size; i++)
        vm->mem[node->address + i] = vm->mem[(*champs)->address + i];
    return (0);
}
