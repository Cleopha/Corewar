/*
** EPITECH PROJECT, 2020
** CoreWar
** File description:
** instruction param checker
*/

#include "corewar_compiler.h"

static int str_contain_only(const char *str, const char *chars)
{
    const char *index = chars;

    for (size_t i = 0; str[i]; i++) {
        while (*index && str[i] != *index)
            index++;
        if (!*index)
            return (0);
        index = chars;
    }
    return (1);
}

static ssize_t label_checker(compiler_t *compiler, char type, const char *word)
{
    if (!compiler || !word)
        return (-2);
    if (!(type & T_IND) && !(type | T_LAB)) {
        print_compiler_error(compiler, "The argument "
            "given to the instruction is invalid.");
        return (-1);
    } else if (!str_contain_only(word, LABEL_CHARS)) {
        print_compiler_error(compiler, "Invalid label name.");
        return (-1);
    }
    return (0);
}

ssize_t direct_checker(compiler_t *compiler, char type, const char *word)
{
    ssize_t checker_result;

    if (!compiler || !word)
        return (-2);
    if (*word == LABEL_CHAR) {
        checker_result = label_checker(compiler, type, word + 1);
        return (!checker_result ? DIR_SIZE : checker_result);
    }
    if (word[0] == '+' || word[1] == '-')
        word++;
    if (!(type & T_DIR) || !str_contain_only(word, "0123456789")) {
        print_compiler_error(compiler, "The argument "
            "given to the instruction is invalid.");
        return (-1);
    }
    return (GET_DIRECT_SIZE(compiler->current_inst->code));
}

ssize_t register_checker(compiler_t *compiler, char type, const char *word)
{
    int register_nb;

    if (!compiler || !word)
        return (-2);
    register_nb = getnbr(word);
    if (!(type & T_REG ) || !str_contain_only(word, "0123456789")
        || register_nb < 1 || register_nb > REG_NUMBER) {
        print_compiler_error(compiler, "Invalid register number.");
        return (-1);
    }
    return (1);
}

ssize_t indirect_checker(compiler_t *compiler, char type, const char *word)
{
    ssize_t checker_result;

    if (!compiler || !word)
        return (-2);
    if (*word == LABEL_CHAR) {
        checker_result = label_checker(compiler, type, word + 1);
        return (!checker_result ? IND_SIZE : checker_result);
    }
    if (word[0] == '+' || word[1] == '-')
        word++;
    if (!(type & T_IND) || !str_contain_only(word, "0123456789")) {
        print_compiler_error(compiler, "The argument "
            "given to the instruction is invalid.");
        return (-1);
    }
    return (IND_SIZE);
}