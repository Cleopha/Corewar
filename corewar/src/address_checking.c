/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** address_checking.c
*/

#include <unistd.h>
#include "vm_struct.h"
#include "champ_struct.h"
#include "vm_prototypes.h"
#include "union.h"

void set_address(elem_t *champ, int nb_champ)
{
    static int mem_pos = 0;

    if (champ->address == -1)
        champ->address = mem_pos;
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

void fill_params(vm_t *vm, elem_t *champ, unsigned char buffer[], int *i)
{
    unsigned char bit = 0;
    int param_len = 0;
    int len = 0;
    union endian endian;

    for (unsigned int j = 0; j < 3; j++) {
        bit = (buffer[*i] >> ((j - 6) * -1)) & 0b11;
        if (bit == 0b01) {
            param_len = 1;
            vm->mem[champ->address + *i + len] = buffer[*i + len];
        } else if (bit == 0b10 || bit == 0b11) {
            param_len = 4;
            endian.nb = endian_conversion(retrieve_int(buffer, *i + len));
        } else
            break;
        for (int k = 0; param_len != 1 && k < param_len; k++)
            vm->mem[champ->address + *i + k + len] = endian.str[k];
        len += param_len;
    }
    *i += len;
}

int fill_with_right_args(vm_t *vm, elem_t *champ)
{
    union endian endian;
    unsigned char buffer[champ->header.prog_size];

    if (read(champ->fd, buffer, champ->header.prog_size) !=
    champ->header.prog_size)
        return (1);
    for (int i = 0; i < champ->header.prog_size; i++) {
        endian.nb = endian_conversion(retrieve_int(buffer, i));
        for (int j = 0; j < 4; j++)
            vm->mem[champ->address + i + j] = endian.str[j];
        i += 4;
        vm->mem[champ->address + i] = buffer[i];
        fill_params(vm, champ, buffer, &i);
    }
    return (0);
}

int fill_mem(vm_t *vm, elem_t *champ)
{
    /*while (champ->prev)
        champ = champ->prev;*/
    if (check_memory_zones(champ, champ))
        return (1);
    while (champ) {
        fill_with_right_args(vm, champ);
        close(champ->fd);
        champ = champ->next;
    }
    return (0);
}
