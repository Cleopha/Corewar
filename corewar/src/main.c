/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** Coline SEGURET's main.c made the 05/06/2020
*/

#include "corewar.h"
#include "vm_prototypes.h"
#include "err_management.h"

void create_param(param_t *param);
int display_error(const char *str);

int loop_error(char **av, param_t *param, elem_t **champs);

int man(char *av, int fd)
{
    my_putstr("USAGE\n");
    my_putstr(av);
    write(fd, " [-dump nbr_cycle] [[-n prog_number] \
[-a load_address] prog_name]\nDESCRIPTION\n-dump nbr_cycledumps the memory \
after the nbr_cycle execution (if the round isn’t\nalready over) with the \
following format: 32 bytes/line\nin hexadecimal (A0BCDEFE1DD3...)\n-n \
prog_numbersets the next program’s number. By default, the first free \
number\nin the parameter order\n-a load_addresssets the next program’s loading \
address. When no address is\nspecified, optimize the addresses so that the \
processes are as far\naway from each other as possible. The addresses are \
MEM_SIZE modulo.\n", 568);
        return (1);
}

int error(int ac, char **av, elem_t **champs, vm_t *vm)
{
    param_t param;
    elem_t *cpy = NULL;

    if (ac == 2 && (tabequals(av[1], "-h", sizeof(char)) ||
       tabequals(av[1], "--help", sizeof(char))))
        return (man(av[0], 1));
    create_param(&param);
    if (loop_error(av, &param, champs))
        return (1);
    cpy = *champs;
    vm->nb_prog = my_list_size(*champs);
    if (1 >= vm->nb_prog || 4 < vm->nb_prog)
        return (display_error(err[ERR_NBR_CHAMPS]));
    for (int i = 0; i < vm->nb_prog; i += 1, cpy = cpy->next)
        set_address(cpy, vm->nb_prog);
    if (param.values[PROGNUMBER] != 0 || param.values[ADDRESS] != -1)
        return (display_error("Invalid parameters\n"));
    vm->dump = param.values[DUMP];
    return (0);
}

int main(int ac, char **av)
{
    vm_t vm = init_vm();
    elem_t *champs = NULL;

    if (error(ac, av, &champs, &vm) || fill_mem(&vm, champs))
        return (1);
    print_mem(&vm);
    loop_vm(&vm, &champs);
    return (0);
}
