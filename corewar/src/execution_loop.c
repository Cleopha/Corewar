/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** execution_loop.c
*/

#include "corewar.h"
#include "vm_prototypes.h"

void check_dump(vm_t *vm, int dump_cp)
{
    vm->dump -= 1;
    if (vm->dump == 0) {
        print_mem(vm);
        vm->dump = dump_cp;
    }
}

void check_alive_champs(vm_t *vm, elem_t *champs, elem_t *first)
{
    vm->cycles_to_die = CYCLE_TO_DIE - (CYCLE_DELTA *
    (int) (vm->nb_live / NBR_LIVE));
    for (; champs != NULL; champs = champs->next) {
        if (champs->is_alive)
            champs->is_alive = false;
        else
            remove_champ(champs);
    }
    champs = first;
}

int loop_vm(vm_t *vm, elem_t *champs)
{
    elem_t *first = champs;
    void (*inst_ptr[])(vm_t *, elem_t *) = {live, ld, st, add, sub, and, or,
    xor, zjmp, ldi, sti, my_fork, lld, lldi, lfork, aff};
    int dump_cp = vm->dump;

    while (my_list_size(first) != 1) {
        for (; champs != NULL; champs = champs->next) {
            //function instruction;
            //
        }
        champs = first;
        check_dump(vm, dump_cp);
        vm->cycles_to_die -= 1;
        if (vm->cycles_to_die == 0)
            check_alive_champs(vm, champs, first);
    }
    return (0);
}