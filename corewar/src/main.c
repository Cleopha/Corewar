/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** Coline SEGURET's main.c made the 05/06/2020
*/

#include "corewar.h"
#include <string.h>

elem_t *add_elem(char *str, int n, int a, elem_t *actual);
elem_t *param_list(char *str, int n, int a);


int error_progNumber(char *av, int *index, param_t *param);
int error_address(char *av, int *index, param_t *param);
int error_dump(char *av, int *index, param_t *param);

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
        return (0);
}

int is_num(char *str)
{
    for (int i = 0; str[i]; i += 1)
        if (!('0' <= str[i] && str[i] <= '9'))
            return (1);
    return (0);
}

void create_param(param_t *param)
{
    param->values[PROGNUMBER] = 0;
    param->values[ADDRESS] = -1;
    param->values[DUMP] = 0;
    for (int i = 0; i < 4; i += 1)
        param->prog[i] = false;
}

int is_champs(char *av, param_t *param, elem_t **ch)
{
    FILE *fd = fopen(av, "r+");
    char *buffer = 0;
    size_t len = 0;

    if (fd == NULL) {
        my_putstr_error("OUVRE PAS\n");
        return (1);
    }
    if (getline(&buffer, &len, fd) == - 1) {
        my_putstr_error("RECUP PAS\n");
        return (1);
    }
    if (*ch == NULL)
        *ch = param_list(strdup(av), param->values[0], param->values[1]);
    else
        *ch = add_elem(strdup(av), param->values[0], param->values[1], *ch);
    param->values[ADDRESS] = -1;
    param->values[PROGNUMBER] = 0;
    return (0);
}

int error(int ac, char **av)
{
    param_t param;
    elem_t *champs = NULL;

    create_param(&param);
    for (int i = 1; av[i]; i += 1) {
        if (tabequals(av[i], "-n", sizeof(char))) {
            if (error_progNumber(av[i + 1], &i, &param))
                return (1);
            continue;
        }
        if (tabequals(av[i], "-a", sizeof(char))) {
            if (error_address(av[i + 1], &i, &param))
                return (1);
            continue;
        }
        if (tabequals(av[i], "-dump", sizeof(char))) {
            if (error_dump(av[i + 1], &i, &param))
                return (1);
            continue;
        }
        if (is_champs(av[i], &param, &champs))
            return (1);
    }
    if (param.values[PROGNUMBER] != 0 || param.values[ADDRESS] != -1) {
        my_putstr_error("Invalid parameters");
        return (1);
    }
    for (; champs != NULL; champs = champs->next)
        printf("%s\n", champs->name);
    return (0);
}

int main(int ac, char **av)
{
    if (error(ac, av))
        return (1);
    return (0);
}
