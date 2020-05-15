/*
** EPITECH PROJECT, 2020
** live.c
** File description:
** Coline SEGURET's live.c made the 05/15/2020
*/

#include "vm_struct.h"
#include "champ_struct.h"

void live(vm_t *vm, elem_t *champs)
{
    int skip = 2;

    champs->pc += skip;
    champs->is_alive = true;
    printf("The player %d (%s) is alive", champs->prog_number, champs->header.prog_name);
    return;
}
