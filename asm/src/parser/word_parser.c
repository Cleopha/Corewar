/*
** EPITECH PROJECT, 2020
** CoreWar
** File description:
** compiler functions
*/

#include "corewar.h"

static void add_node(inst_t **instructions, char *bytes, size_t size)
{
    inst_t *instruction;

    if (!instructions || !bytes || !size)
        return;
    instruction = malloc(sizeof(inst_t));
    if (!instruction)
        return;
    *instruction = (inst_t) {bytes, size, NULL};
    if (*instructions)
        (*instructions)->next = instruction;
    *instructions = instruction;
}

static ssize_t parse_instruction(compiler_t *compiler, const char *line)
{
    char *bytes = NULL;
    ssize_t bytes_size = 0;
    char **words;

    if (!compiler)
        return (0);
    words = (char **) tabsplit_clean(line, " ", sizeof(char));
    if (!words)
        return (0);
    bytes_size = cw_compile_instruction(compiler, &bytes, words);
    mcfree(words, 1, NULL);
    add_node(&compiler->instructions, bytes, bytes_size);
    return ((bytes_size < 0) ? -2 : bytes_size);
}

static ssize_t parse_line(compiler_t *compiler)
{
    size_t n = 0;
    char *line = NULL;
    ssize_t size;
    ssize_t bytes_size = 0;

    if (!compiler || !compiler->file)
        return (-1);
    size = getline(&line, &n, compiler->file);
    if (size < 2 || tabstart(line, "#", sizeof(char))
        || tabstart(line, ".", sizeof(char))) {
        free(line);
        return (0);
    }
    line[size - 1] = 0;
    for (ssize_t i = 0; i < size; i++)
        if (line[i] == ',')
            line[i] = ' ';
    bytes_size = parse_instruction(compiler, line);
    free(line);
    compiler->current_byte += bytes_size;
    return (bytes_size);
}

int cw_compile(compiler_t *compiler)
{
    ssize_t line_result = 0;

    if (!compiler || !compiler->file)
        return (0);
    do {
        compiler->current_byte += line_result;
        line_result = parse_line(compiler);
        compiler->current_line++;
    } while (line_result >= 0);
    cw_flags_clear(compiler);
    return (line_result >= 0 ? 1 : 0);
}