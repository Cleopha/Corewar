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
        printf("champ: %d, %d\n", champ->address, champ->header.prog_size);
        printf("ch: %d, %d\n", ch->address, ch->header.prog_size);
        if (champ->address >= ch->address &&
            champ->address <= ch->address + ch->header.prog_size) {
            return (1);
        }
        if (ch->address < champ->address &&
        ch->address < (ch->address + ch->header.prog_size) % MEM_SIZE)
            return (1);
        if (check_memory_zones(champ, ch->next))
            return (1);
        champ = champ->next;
        ch = champ->next;
    }
    return (0);
}

int fill_mem(vm_t *vm, elem_t *champ, int fd)
{
    if (check_memory_zones(champ, champ->next))
        return (1);
    return (0);
}
