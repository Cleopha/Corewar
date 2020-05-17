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
    int nb = (int)vm->nb_live / NBR_LIVE;

    vm->cycles_to_die = CYCLE_TO_DIE - (CYCLE_DELTA * nb);
    for (elem_t *current = *champs; current; current = (current)->next) {
        if (vm->is_alive[current->prog_number - 1]) {
            vm->is_alive[current->prog_number - 1] = false;
        }
        else if (vm->nb_prog > 1) {
            *champs = remove_champ(&current);
            vm->nb_prog -= 1;
        } else {
            break;
        }
    }
}

void exec_champ_inst(vm_t *vm, elem_t *champs, int (*inst_ptr[])(vm_t *,
                        elem_t *))
{
    if (vm->mem[champs->pc] > 0 && vm->mem[champs->pc] < 17)
        inst_ptr[vm->mem[champs->pc] - 1](vm, champs);
}

void check_champ_inst(vm_t *vm, elem_t *champs, int (*inst_ptr[])(vm_t *,
                        elem_t *))
{
    for (elem_t *current = champs; current; current = current->next) {
        if ((current)->instruction_cycles == 0) {
            exec_champ_inst(vm, current, inst_ptr);
        } else
            (current)->instruction_cycles -= 1;
    }
}

int loop_vm(vm_t *vm, elem_t *champs)
{
    int (*inst_ptr[])(vm_t *, elem_t *) = {live, ld, st, add, sub, and, or,
    xor, zjmp, ldi, sti, my_fork, lld, lldi, lfork, aff};
    int dump_cp = vm->dump;

    while (vm->nb_prog > 1) {
        check_champ_inst(vm, champs, inst_ptr);
        if (vm->dump >= 0)
            check_dump(vm, dump_cp);
        vm->cycles_to_die -= 1;
        if (vm->cycles_to_die == 0) {
            check_alive_champs(vm, &champs);
        }
    }
    my_putstr("\nThe player ");
    my_putnbr(champs->prog_number);
    my_putstr(" (");
    my_putstr(champs->header.prog_name);
    my_putstr(") has won.\n");
    return (0);
}
