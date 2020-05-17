/*
** EPITECH PROJECT, 2020
** aff.c
** File description:
** Coline SEGURET's aff.c made the 05/15/2020
*/

#include "vm_prototypes.h"
#include "cubee.h"

int aff(vm_t *vm, elem_t *champs)
{
    unsigned char params[4];
    int ind = 0;

    champs->index_actual += 1;
    champs->instruction_cycles = 2;
    set_param_with_byte(vm->mem[champs->index_actual], params);
    champs->index_actual += 1;
    ind = get_index_reg(vm, champs);
    my_putchar((char)(champs->reg[ind] % 256));
    champs->pc = champs->index_actual;
    return (0);
}
