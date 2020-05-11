/*
** EPITECH PROJECT, 2020
** CoreWar
** File description:
** writer function
*/

#include "corewar_compiler.h"

int write_instructions(compiler_t *compiler, const char *filename)
{
    int fd = 0;
    inst_t *current;

    if (!filename || !compiler || !compiler->instructions)
        return (84);
    fd = open(filename, O_CREAT | O_RDWR);
    if (fd == -1)
        return (84);
    current = compiler->instructions;
    do {
        write(fd, current->bytes, current->size);
        current = current->next;
    } while (current);
    return (0);
}
