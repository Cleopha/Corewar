/*
** EPITECH PROJECT, 2020
** CoreWar
** File description:
** writer function
*/

#include "corewar_compiler.h"

int write_instructions(inst_t *instructions, const char *filename)
{
    int fd = 0;

    if (!filename || !instructions)
        return (84);
    fd = open(filename, O_CREAT | O_RDWR);
    if (fd == -1)
        return (84);
    do {
        write(fd, instructions->bytes, instructions->size);
        instructions = instructions->next;
    } while (instructions);
    return (0);
}
