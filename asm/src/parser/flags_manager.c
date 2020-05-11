/*
** EPITECH PROJECT, 2020
** CoreWar
** File description:
** flag manager
*/

#include "corewar_compiler.h"

static struct flag_s *cw_flags_get(compiler_t *compiler, size_t hash)
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
    struct flag_s *node;

    if (!flag || !compiler)
        return (-2);
    node = cw_flags_get(compiler, strhash(flag));
    return (node ? (ssize_t) node->location : -1);
}

int wc_flags_compile(compiler_t *compiler, char *flag, char *bytes,
    size_t size)
{
    ssize_t location;

    if (!compiler || !bytes)
        return (-1);
    location = cw_flags_location(compiler, flag);
    if (location == -2)
        return (-1);
    else if (location == -1) {
        // add flag queue function (by Eddy)
        return (0);
    }
    *((int *) bytes) = (int) (location - (compiler->current_byte + size));
    return (1);
}

int cw_flags_register(compiler_t *compiler, char *flag, size_t loc)
{
    size_t hash;
    struct flag_s *registered;

    if (!flag || !compiler)
        return (-1);
    hash = strhash(flag);
    registered = cw_flags_get(compiler, hash);
    if (registered)
        return (0);
    registered = malloc(sizeof(struct flag_s));
    if (!registered)
        return (-1);
    *registered = (struct flag_s) {hash, loc, compiler->flags};
    compiler->flags = registered;
    return (1);
}

void cw_flags_clear(compiler_t *compiler)
{
    struct flag_s *current;
    struct flag_s *next;

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