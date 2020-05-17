/*
** EPITECH PROJECT, 2020
** CoreWar
** File description:
** compiler instruction param
*/

#include "corewar_compiler.h"

static void cw_fix_param_byte(op_t *inst, char *param_byte)
{
    if (!inst || !param_byte)
        return;
    *param_byte = *param_byte << (2 * (MAX_ARGS_NUMBER - inst->nbr_args));
}

static ssize_t cw_get_instruction_param_length(compiler_t *compiler, char type,
    const char *word, char *param_byte)
{
    ssize_t size_param = 0;

    if (!compiler || !word || !param_byte)
        return (-2);
    *param_byte = *param_byte << 2;
    if (word[0] == DIRECT_CHAR) {
        size_param = direct_checker(compiler, type, word + 1);
        *param_byte = *param_byte | 2;
    } else if (word[0] == 'r') {
        size_param = register_checker(compiler, type, word + 1);
        *param_byte = *param_byte | 1;
    } else {
        size_param = indirect_checker(compiler, type, word);
        *param_byte = *param_byte | 3;
    }
    return (size_param);
}

static ssize_t cw_get_instruction_length(compiler_t *compiler, char **words,
    char *param_byte)
{
    ssize_t size = 0;
    ssize_t size_param = 0;

    *param_byte = 0;
    if (!compiler || !compiler->current_inst || !words)
        return (-2);
    for (size_t i = 0; size_param >= 0
        && i < (size_t) compiler->current_inst->nbr_args; i++) {
        size += size_param;
        size_param = cw_get_instruction_param_length(compiler,
            compiler->current_inst->type[i], words[i], param_byte);
    }
    size += size_param;
    return (size_param >= 0 ? size : size_param);
}

static ssize_t cw_write_instruction_param(compiler_t *compiler, char *byte,
    char *word)
{
    ssize_t size = GET_DIRECT_SIZE(compiler->current_inst->code);
    int value;

    if (!compiler || !byte || !word)
        return (-2);
    if (word[0] == DIRECT_CHAR && (size != 2 || word[1] == LABEL_CHAR)) {
        if (word[1] == LABEL_CHAR)
            return (cw_flags_compile(compiler, word + 2, byte));
        else
            value = my_atoi(word + 1);
    } else if (word[0] == 'r') {
        size = 1;
        value = (char) my_atoi(word + 1);
    } else {
        size = 2;
        value = (short) my_atoi(word + (word[0] == '%'));
    }
    cw_write_inv_endian(byte, (char *) &value, size);
    return (size);
}

ssize_t cw_compile_instruction_param(compiler_t *compiler, char **bytes,
    char **words)
{
    ssize_t instruction_len;
    char param_byte;
    ssize_t location = 1;

    if (!compiler || !compiler->current_inst || !bytes || !words)
        return (-2);
    instruction_len = cw_get_instruction_length(compiler, words, &param_byte);
    if (instruction_len < 0)
        return (instruction_len);
    instruction_len += IS_PARAM_BYTE(compiler->current_inst->code) + 1;
    *bytes = malloc(instruction_len);
    if (!*bytes)
        return (-2);
    **bytes = compiler->current_inst->code;
    if (IS_PARAM_BYTE(compiler->current_inst->code)) {
        cw_fix_param_byte(compiler->current_inst, &param_byte);
        (*bytes)[location++] = param_byte;
    }
    for (unsigned char i = 0; i < compiler->current_inst->nbr_args; i++)
        location += cw_write_instruction_param(compiler,
            *bytes + location, words[i]);
    return (instruction_len);
}