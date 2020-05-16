/*
** EPITECH PROJECT, 2020
** live.c
** File description:
** Coline SEGURET's live.c made the 05/15/2020
*/

#include "vm_struct.h"
#include "champ_struct.h"
#include "cubee.h"

void live( __attribute__((unused))vm_t *vm, elem_t **champs)
{
    int skip = 2;

    (*champs)->instruction_cycles = 10;
    (*champs)->pc += skip;
    (*champs)->is_alive = true;
    my_putstr("The player ");
    my_putnbr((*champs)->prog_number);
    my_putstr(" (");
    my_putstr((*champs)->header.prog_name);
    my_putstr(") is alive\n");
}
