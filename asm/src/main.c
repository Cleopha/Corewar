/*
** EPITECH PROJECT, 2020
** CoreWar
** File description:
** main function
*/

#include "corewar.h"

int main(int argc, char **argv)
{
    FILE *file;
    compiler_t compiler __attribute__ ((__cleanup__ (free_compiler))) = {0};

    LOG("%s\n", "Welcome in debug mode!");
    if (argc < 2) {
        write(2, "Usage: ./asm file_name[.s] ....\n", 32);
        return (84);
    }
    file = fopen(argv[1], "r");
    if (!file) {
        write(2, "Error in function open: No such file or directory.\n", 51);
        return (84);
    }
    compiler.file_path = argv[1];
    compiler.file = file;
    cw_compile(&compiler);
    fclose(file);
    return (write_instructions(&compiler, NULL));
}