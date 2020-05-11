/*
** EPITECH PROJECT, 2020
** CoreWar
** File description:
** compiler instruction
*/

#include "corewar_compiler.h"

static op_t *get_instruction(const char *instruction)
{
    unsigned int hash = strhash(instruction);

    for (size_t i = 0; op_tab[i].mnemonique; i++)
        if (op_tab[i].hash == hash)
            return (op_tab + i);
    return (NULL);
}

static ssize_t cw_register_flag(compiler_t *compiler, size_t flag_len,
    char **words)
{
    int register_error;
    if (tablen(words, sizeof(char *)) != 1)
        return (-1);
    words[0][flag_len - 1] = 0;
    register_error = cw_flags_register(compiler, words[0], compiler->current_byte) == 0;
    if (register_error)
        print_compiler_error(compiler, "Multiple "
                                       "definition of the same label.");
    words[0][flag_len - 1] = ':';
    return (0);
}

static ssize_t cw_write_instruction(compiler_t *compiler, char **bytes,
    char **words)
{
    op_t *instruction;

    if (!compiler || !bytes || !words)
        return (-1);
    instruction = get_instruction(words[0]);
    if (!instruction) {
        my_putstr_error("Unknown instruction !\n");
        return (-1);
    }
    if (tablen(words + 1, sizeof(char *) != instruction->nbr_args)) {
        my_putstr_error("Invalid argument number.");
        return (-1);
    }
    return (0);
}

ssize_t cw_compile_instruction(compiler_t *compiler, char **bytes,
    char **words)
{
    size_t flag_len;

    if (!compiler || !bytes || !words)
        return (-1);
    flag_len = tablen(words[0], sizeof(char));
    if (words[0][flag_len - 1] == ':') {
        if (cw_flags_register(compiler, words[0], compiler->current_byte) == 0)
            print_compiler_error(compiler, "Multiple "
                "definition of the same label.");
        return (0);
    }
    return (cw_write_instruction(compiler, bytes, words));
}