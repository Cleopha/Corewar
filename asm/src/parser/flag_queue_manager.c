/*
** EPITECH PROJECT, 2020
** CoreWar
** File description:
** flag queue manager
*/

#include "corewar_compiler.h"

static void cw_flags_queue_remove(compiler_t *compiler, flag_queue_t *node)
{
    if (!compiler || !node)
        return;
    if (compiler->flags_queue == node)
        compiler->flags_queue = node->next;
    if (node->before)
        node->before->next = node->next;
    if (node->next)
        node->next->before = node->before;
    free(node);
}

static flag_queue_t *cw_flags_queue_get(flag_queue_t *start, size_t hash)
{
    flag_queue_t *current = start;

    while (current) {
        if (current->hash == hash)
            return (current);
        current = current->next;
    }
    return (NULL);
}

int cw_flags_queue_compile(compiler_t *compiler, char *flags)
{
    size_t hash = strhash(flags);
    ssize_t location = cw_flags_location(compiler, flags);
    flag_queue_t *current;
    flag_queue_t *remove;
    size_t size;
    int value;

    if (location < 0)
        return ((int) location);
    current = cw_flags_queue_get(compiler->flags_queue, strhash(flags));
    while (current) {
        size = GET_DIRECT_SIZE(current->instruction->code);
        value = (size == 2) ? ((short) (location - current->location))
            : ((int) (location - current->location));
        cw_write_inv_endian(current->flag_ptr, (char *) &value, size);
        remove = current;
        current = cw_flags_queue_get(current->next, hash);
        cw_flags_queue_remove(compiler, remove);
    }
    return (0);
}

int cw_flags_queue_register(compiler_t *compiler, char *flag, size_t loc,
    char *flag_ptr)
{
    size_t hash;
    flag_queue_t *registered;

    if (!flag || !compiler)
        return (-2);
    hash = strhash(flag);
    registered = malloc(sizeof(flag_queue_t));
    if (!registered)
        return (-2);
    if (compiler->flags_queue)
        compiler->flags_queue->before = registered;
    *registered = (flag_queue_t) {hash, loc, compiler->current_line,
        flag_ptr, compiler->current_inst, NULL, compiler->flags_queue};
    compiler->flags_queue = registered;
    return (0);
}

void cw_flags_queue_clear(compiler_t *compiler)
{
    flag_queue_t *current;
    flag_queue_t *next;

    if (!compiler)
        return;
    current = compiler->flags_queue;
    compiler->flags_queue = NULL;
    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
}