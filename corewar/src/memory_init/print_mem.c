/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** print_mem.c
*/

#include "cubee.h"
#include "vm_struct.h"
#include "put_hexa.h"

void print_mem(vm_t *vm)
{
    my_put_hexa_maj(0);
    my_putstr("\t:");
    for (int i = 0; i < MEM_SIZE; i++) {
        if (i % 32 == 0 && i != 0) {
            my_putchar('\n');
            my_put_hexa_maj((size_t)i);
            my_putstr("\t:");
        }
        my_putchar(' ');
        if (vm->mem[i] < 16)
            my_putchar('0');
        my_put_hexa_maj((size_t)vm->mem[i]);
    }
    my_putchar('\n');
}