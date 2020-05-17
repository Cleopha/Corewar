/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** mem_init.c
*/

#include "vm_struct.h"
#include "corewar_operation.h"

vm_t init_vm(void)
{
    vm_t vm;

    for (size_t i = 0; i < MEM_SIZE; i++)
        vm.mem[i] = 0;
    for (size_t i = 0; i < 4; i++)
        vm.is_alive[i] = false;
    vm.nb_live = 0;
    vm.cycles_to_die = CYCLE_TO_DIE;
    vm.nb_prog = 0;
    return (vm);
}
