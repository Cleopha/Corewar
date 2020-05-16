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

void check_alive_champs(vm_t *vm, elem_t **champs)
{
    vm->cycles_to_die = CYCLE_TO_DIE - (CYCLE_DELTA *
    (int) (vm->nb_live / NBR_LIVE));
    for (; *champs != NULL; *champs = (*champs)->next) {
        if ((*champs)->is_alive)
            (*champs)->is_alive = false;
        else {
            remove_champ(champs);
            vm->nb_prog -= 1;
        }
    }
    for (; *champs && (*champs)->prev; *champs = (*champs)->prev);
}

void exec_champ_inst(vm_t *vm, elem_t **champs, void (*inst_ptr[])(vm_t *,
                        elem_t **))
{
    if (vm->mem[(*champs)->pc] > 0 && vm->mem[(*champs)->pc] < 17)
        inst_ptr[vm->mem[(*champs)->pc] - 1](vm, champs);
}

void check_champ_inst(vm_t *vm, elem_t **champs, void (*inst_ptr[])(vm_t *,
                        elem_t **))
{
    for (; *champs != NULL; *champs = (*champs)->next) {
        if ((*champs)->instruction_cycles == 0)
            exec_champ_inst(vm, champs, inst_ptr);
        else
            (*champs)->instruction_cycles -= 1;
    }
}

int loop_vm(vm_t *vm, elem_t **champs)
{
    void (*inst_ptr[])(vm_t *, elem_t **) = {live, ld, st, add, sub, and, or,
    xor, zjmp, ldi, sti, my_fork, lld, lldi, lfork, aff};
    int dump_cp = vm->dump;

    while (vm->nb_prog != 1) {
        check_champ_inst(vm, champs, inst_ptr);
        if (vm->dump >= 0)
            check_dump(vm, dump_cp);
        vm->cycles_to_die -= 1;
        if (vm->cycles_to_die == 0)
            check_alive_champs(vm, champs);
    }
    return (0);
}
