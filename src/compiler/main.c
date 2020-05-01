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
    inst_t *instructions __attribute__ ((__cleanup__ (free_instructions)));

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
    instructions = cw_compile(file);
    fclose(file);
    return (write_instructions(instructions, NULL));
}
