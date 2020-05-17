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

static ssize_t cw_write_instruction(compiler_t *compiler, char **bytes,
    char **words)
{
    if (!compiler || !bytes || !words)
        return (-2);
    compiler->current_inst = get_instruction(words[0]);
    if (!compiler->current_inst) {
        print_compiler_error(compiler, "Invalid instruction.");
        return (-1);
    }
    if (tablen(words + 1, sizeof(char *))
        != (size_t) compiler->current_inst->nbr_args) {
        print_compiler_error(compiler, "The argument given to the "
            "instruction is invalid.");
        return (-1);
    }
    return (cw_compile_instruction_param(compiler, bytes, words + 1));
}

static ssize_t cw_register_flag(compiler_t *compiler, size_t flag_len,
    char **words, char **bytes)
{
    int register_error;

    if (!compiler || !words)
        return (-2);
    words[0][flag_len - 1] = 0;
    register_error = cw_flags_register(compiler, words[0],
        compiler->current_byte);
    if (register_error == 0) {
        print_compiler_error(compiler, "Multiple "
            "definition of the same label.");
        return (-1);
     } else
         cw_flags_queue_compile(compiler, words[0]);
    words[0][flag_len - 1] = ':';
    return (words[1] ? cw_write_instruction(compiler, bytes, words + 1)
        : 0);
}

ssize_t cw_compile_instruction(compiler_t *compiler, char **bytes,
    char **words)
{
    size_t flag_len;

    if (!compiler || !bytes || !words)
        return (-2);
    flag_len = tablen(words[0], sizeof(char));
    if (words[0][flag_len - 1] == ':')
        return (cw_register_flag(compiler, flag_len, words, bytes));
    return (cw_write_instruction(compiler, bytes, words));
}