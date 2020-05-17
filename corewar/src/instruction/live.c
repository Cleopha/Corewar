/*
** EPITECH PROJECT, 2020
** live.c
** File description:
** Coline SEGURET's live.c made the 05/15/2020
*/

#include "vm_struct.h"
#include "champ_struct.h"
#include "cubee.h"

int live(vm_t *vm, elem_t *champs)
{
    int skip = 5;

    champs->instruction_cycles = 10;
    champs->index_actual += skip;
    vm->is_alive[champs->prog_number - 1] = true;
    vm->nb_live += 1;
    my_putstr("The player ");
    my_putnbr(champs->prog_number);
    my_putstr(" (");
    my_putstr(champs->header.prog_name);
    my_putstr(") is alive\n");
    champs->pc = champs->index_actual;
    return (0);
}
