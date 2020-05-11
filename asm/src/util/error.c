/*
** EPITECH PROJECT, 2020
** CoreWar
** File description:
** print error functions
*/

#include "corewar_util.h"
#include "corewar_compiler.h"

void print_error(const char *file, size_t line, const char *msg)
{
    char *line_str;

    my_putstr_error("\033[1;37masm");
    if (file) {
        write(2, ", ", 2);
        my_putstr_error(file);
    }
    line_str = line ? ntoa(line, "0123456789", 0) : NULL;
    if (line_str) {
        write(2, ", ", 2);
        write(2, "line ", 5);
        my_putstr_error(line_str);
        free(line_str);
    }
    my_putstr_error(": \033[0m\033[1;36m");
    my_putstr_error(msg ? msg : "Error.");
    my_putstr_error("\033[0m");
}

void print_compiler_error(compiler_t *compiler, const char *msg)
{
    if (!compiler)
        return;
    print_error(compiler->file_path, compiler->current_line + 1, msg);
}