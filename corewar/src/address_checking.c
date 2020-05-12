/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** address_checking.c
*/

#include "vm_struct.h"
#include "champ_struct.h"
#include "vm_prototypes.h"

int check_memory_zones(elem_t *champ, elem_t *ch)
{
    while (champ->next && ch) {
        if (champ->address >= ch->address &&
            champ->address <= ch->address + ch->header.prog_size)
            return (84);
        if (ch->address < champ->address && ch->address <
            (ch->address + champ->next->header.prog_size) % MEM_SIZE)
            return (84);
        if (check_memory_zones(champ, ch->next) == 84)
            return (84);
        champ = champ->next;
        ch = champ->next;
    }
    return (0);
}

int fill_mem(vm_t *vm, elem_t *champ, int fd)
{
    while (champ->prev)
        champ = champ->prev;
    if (check_memory_zones(champ, champ->next) == 84)
        return (84);
    return (0);
}