/*
** EPITECH PROJECT, 2020
** CoreWar
** File description:
** instructions
*/

#include <stdlib.h>

#include "corewar_compiler.h"

static void free_instructions(inst_t **instructions)
{
    inst_t *next;

    if (!instructions || !*instructions)
        return;
    do {
        next = (*instructions)->next;
        free((*instructions)->bytes);
        free(*instructions);
        *instructions = next;
    } while(*instructions);
}

void free_compiler(compiler_t *compiler)
{
    if (!compiler)
        return;
    free_instructions(&compiler->instructions);
    cw_flags_clear(compiler);
}