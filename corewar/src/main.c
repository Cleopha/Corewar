/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** Coline SEGURET's main.c made the 05/06/2020
*/

#include "corewar.h"

int man(char *av)
{
    my_putstr("USAGE\n");
    my_putstr(av);
    write(1, " [-dump nbr_cycle] [[-n prog_number] \
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

int main(int ac, char **av)
{
    if (ac == 2 && (tabequals(av[1], "-h", sizeof(char)) ||
                    tabequals(av[1], "--helps", sizeof(char))))
        man(av[0]);
    return(1);
}
