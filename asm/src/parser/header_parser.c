/*
** EPITECH PROJECT, 2020
** CoreWar
** File description:
** header parser
*/

#include "corewar_compiler.h"

static char *get_delimiter(char *line)
{
    if (!line)
        return (NULL);
    for (; *line && *line != '"'; line++);
    return (!*line ? NULL : line);
}

static ssize_t parser_value(char *line, char *buffer, size_t buffer_size)
{
    char *delimiters[2];
    size_t size;

    if (!line || !buffer || !buffer_size)
        return (-2);
    delimiters[0] = get_delimiter(line);
    if (!delimiters[0])
        return (-1);
    delimiters[1] = get_delimiter(++delimiters[0]);
    if (!delimiters[1] || delimiters[1][1])
        return (-1);
    size = delimiters[1] - delimiters[0];
    if (size > buffer_size)
        return (0);
    for (size_t i = 0; i < size; i++)
        buffer[i] = delimiters[0][i];
    for (size_t i = size; i < buffer_size; i++)
        buffer[i] = 0;
    return (1);
}

static ssize_t parse_name(compiler_t *compiler, char *line)
{
    ssize_t parse_result;

    if (compiler->header_complete & 1) {
        print_compiler_error(compiler, "The name can only be defined"
            " once.");
        return (-1);
    }
    compiler->header_complete |= 1;
    parse_result = parser_value(line, compiler->header.prog_name,
        PROG_NAME_LENGTH);
    if (!parse_result) {
        print_compiler_error(compiler, "The program name is too long.");
        return (-1);
    } else if (parse_result == -1)
        print_compiler_error(compiler, "Syntax error.");
    return (parse_result > 0 ? 0 : parse_result);
}

static ssize_t parse_comment(compiler_t *compiler, char *line)
{
    ssize_t parse_result;

    if (compiler->header_complete & 2) {
        print_compiler_error(compiler, "The comment can only be defined"
            " once.");
        return (-1);
    }
    compiler->header_complete |= 2;
    parse_result = parser_value(line, compiler->header.comment,
        COMMENT_LENGTH);
    if (!parse_result) {
        print_compiler_error(compiler, "The comment is too long.");
        return (-1);
    } else if (parse_result == -1)
        print_compiler_error(compiler, "Syntax error.");
    return (parse_result > 0 ? 0 : parse_result);
}

ssize_t cw_parse_header(compiler_t *compiler, char *line)
{
    if (!compiler || !line)
        return (-2);
    if (tabstart(line, "name", sizeof(char)))
        return (parse_name(compiler, line + 4));
    else if (tabstart(line, "comment", sizeof(char)))
        return (parse_comment(compiler, line + 7));
    print_compiler_error(compiler, "Invalid instruction.");
    return (-1);
}