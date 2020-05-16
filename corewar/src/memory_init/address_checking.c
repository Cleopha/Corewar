/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** address_checking.c
*/

#include <unistd.h>
#include "vm_prototypes.h"
#include "my_memset.h"

void set_address(elem_t *champ, int nb_champ)
{
    static int mem_pos = 0;

    if (champ->address == -1)
        champ->address = mem_pos;
    champ->pc = champ->address;
    champ->index_actual = champ->address;
    mem_pos += MEM_SIZE / nb_champ;
}

int check_memory_zones(elem_t *champ, elem_t *begin)
{
    elem_t *ch = begin;

    while (ch && champ->next) {
        if (champ == ch)
            return (check_memory_zones(champ, ch->next));
        if (champ->address == -1 || ch->address == -1)
            return (0);
        if (champ->address >= ch->address &&
            champ->address <= ch->address + ch->header.prog_size) {
            return (1);
        }
        if (ch->address + ch->header.prog_size > MEM_SIZE)
            return (1);
        if (check_memory_zones(champ, ch->next) == 1)
            return (1);
        champ = champ->next;
        ch = begin;
    }
    return (0);
}

int fill_with_right_args(vm_t *vm, elem_t *champ)
{
    unsigned char buffer[champ->header.prog_size];
    unsigned char inst;

    my_memset(buffer, 0, champ->header.prog_size);
    if (read(champ->fd, buffer, champ->header.prog_size) !=
    champ->header.prog_size)
        return (1);
    for (int i = 0; i < champ->header.prog_size;) {
        vm->mem[champ->address + i] = buffer[i];
        inst = vm->mem[champ->address + i];
        i += 1;
        if (inst == 1 || inst == 2 || inst == 6 || inst == 7 || inst == 8)
            vm->dir_size = 4;
        else
            vm->dir_size = 2;
        fill_params(vm, champ, buffer, &i);
    }
    return (0);
}

int fill_mem(vm_t *vm, elem_t *champ)
{
    if (check_memory_zones(champ, champ))
        return (1);
    while (champ) {
        fill_with_right_args(vm, champ);
        close(champ->fd);
        if (!champ->next)
            break;
        champ = champ->next;
    }
    return (0);
}
