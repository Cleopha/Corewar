/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** mem_init.c
*/

#include "vm_struct.h"

vm_t init_vm(void)
{
    vm_t vm;

    for (size_t i = 0; i < MEM_SIZE; i++)
        vm.mem[i] = 0;
    vm.nb_live = 0;
    vm.cycle_decrease = 0;
    vm.cycles_to_die = 0;
    return (vm);
}