/*
** EPITECH PROJECT, 2020
** CoreWar
** File description:
** compiler functions
*/

#include "corewar.h"

static void free_str(char **str)
{
    if (str)
        free(*str);
}

static void write_header(compiler_t *compiler)
{
    int magic_value = COREWAR_EXEC_MAGIC;

    if (!compiler)
        return;
    compiler->header.prog_size = (int) compiler->current_byte;
    cw_write_inv_endian((char *) &compiler->header.magic,
        (char *) &magic_value, sizeof(int));
    cw_write_inv_endian((char *) &compiler->header.prog_size,
        (char *) &compiler->current_byte, sizeof(int));
}

static ssize_t parse_instruction(compiler_t *compiler, char *line)
{
    char *bytes = NULL;
    ssize_t bytes_size = 0;
    char **words;
    int add_result = 0;

    if (!compiler)
        return (0);
    for (ssize_t i = 0; line[i]; i++)
        if (line[i] == ',' || line[i] == '\t')
            line[i] = ' ';
    words = (char **) tabsplit_clean(line, " ", sizeof(char));
    if (!words)
        return (0);
    bytes_size = cw_compile_instruction(compiler, &bytes, words);
    mcfree(words, 1, NULL);
    if (bytes_size > 0)
        add_result = cw_add_instruction(compiler, bytes, bytes_size);
    return (add_result < 0 ? add_result : bytes_size);
}

static ssize_t parse_line(compiler_t *compiler)
{
    size_t n = 0;
    char *line __attribute__ ((__cleanup__ (free_str))) = NULL;
    ssize_t size;
    ssize_t bytes_size = 0;

    if (!compiler || !compiler->file)
        return (-2);
    size = getline(&line, &n, compiler->file);
    if (size < 0 || !line)
        return (-3);
    else if (size < 2)
        return (0);
    if (*line == '#')
        return (0);
    if (line[--size] == '\n')
        line[size] = 0;
    if (*line == '.')
        return (cw_parse_header(compiler, line + 1));
    bytes_size = parse_instruction(compiler, line);
    return (bytes_size);
}

ssize_t cw_compile(compiler_t *compiler)
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
    if (line_result >= 0 && compiler->flags_queue != NULL) {
        line_result = -1;
        print_error(compiler->file_path, compiler->flags_queue->line + 1,
            "Undefined label.");
    }
    cw_flags_queue_clear(compiler);
    write_header(compiler);
    return (line_result == -3 ? 0 : line_result);
}