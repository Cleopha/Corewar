/*
** EPITECH PROJECT, 2020
** CoreWar
** File description:
** flag manager
*/

#include "corewar_compiler.h"

static flag_t *cw_flags_get(compiler_t *compiler, size_t hash)
{
    struct flag_s *current;

    if (!compiler)
        return (NULL);
    current = compiler->flags;
    while (current) {
        if (current->hash == hash)
            return (current);
        current = current->next;
    }
    return (NULL);
}

ssize_t cw_flags_location(compiler_t *compiler, char *flag)
{
    flag_t *node;

    if (!flag || !compiler)
        return (-2);
    node = cw_flags_get(compiler, strhash(flag));
    return (node ? (ssize_t) node->location : -1);
}

int cw_flags_compile(compiler_t *compiler, char *flag, char *bytes)
{
    ssize_t location;
    size_t value_size;
    int value;

    if (!compiler || !bytes)
        return (-2);
    value_size = GET_DIRECT_SIZE(compiler->current_inst->code);
    location = cw_flags_location(compiler, flag);
    if (location == -2)
        return (-2);
    else if (location == -1) {
        value = cw_flags_queue_register(compiler, flag,
            compiler->current_byte, bytes);
        if (value < 0)
            return (value);
        return (value_size);
    }
    value = (value_size == 2) ?
        ((short) (location - (compiler->current_byte)))
        : ((int) (location - (compiler->current_byte)));
    cw_write_inv_endian(bytes, (char *) &value, value_size);
    return (value_size);
}

int cw_flags_register(compiler_t *compiler, char *flag, size_t loc)
{
    size_t hash;
    flag_t *registered;

    if (!flag || !compiler)
        return (-2);
    hash = strhash(flag);
    registered = cw_flags_get(compiler, hash);
    if (registered)
        return (0);
    registered = malloc(sizeof(flag_t));
    if (!registered)
        return (-2);
    *registered = (flag_t) {hash, loc, compiler->flags};
    compiler->flags = registered;
    return (1);
}

void cw_flags_clear(compiler_t *compiler)
{
    flag_t *current;
    flag_t *next;

    if (!compiler)
        return;
    current = compiler->flags;
    compiler->flags = NULL;
    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
}