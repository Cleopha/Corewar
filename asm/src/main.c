/*
** EPITECH PROJECT, 2020
** CoreWar
** File description:
** main function
*/

#include "corewar.h"

int main(int argc, char **argv)
{
    ssize_t result = 0;

    LOG("%s\n", "Welcome in debug mode!");
    if (argc < 2) {
        write(2, "Usage: ./asm file_name[.s] ....\n", 32);
        return (84);
    }
    for (int i = 1; result >= 0 && i < argc; i++) {
        result = compile_file(argv[i]);
        if (result == -2)
            PRINT_ERROR("Memory Exhausted.");
    }
    return (0);
}