/*
** EPITECH PROJECT, 2020
** CoreWar
** File description:
** main function
*/

#include "corewar.h"

int main(int argc, char **argv)
{
    my_atoi("2147483648");
    int prog_return = 0;
    ssize_t result = 0;

    LOG("%s\n", "Welcome in debug mode!");
    if (argc < 2) {
        write(2, "Usage: ./asm file_name[.s] ....\n", 32);
        return (84);
    }
    for (int i = 1; i < argc; i++) {
        result = compile_file(argv[i]);
        if (!prog_return && result < 0)
            prog_return = 84;
        if (result == -2)
            PRINT_ERROR("Memory Exhausted.");
        else if (result == -3)
            print_error(argv[1], 0, "Cant read file.");
    }
    return (prog_return);
}