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
    while (*instructions) {
        if ((*instructions)->before)
            (*instructions)->before->next = NULL;
        next = (*instructions)->next;
        if (next)
            next->before = NULL;
        free((*instructions)->bytes);
        free(*instructions);
        *instructions = next;
    }
}

void free_compiler(compiler_t *compiler)
{
    if (!compiler)
        return;
    free_instructions(&compiler->instructions);
    cw_flags_clear(compiler);
    cw_flags_queue_clear(compiler);
    if (compiler->file)
        fclose(compiler->file);
}