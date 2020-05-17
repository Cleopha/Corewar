/*
** EPITECH PROJECT, 2020
** CoreWar
** File description:
** main function
*/

#include "corewar_compiler.h"

static void free_value(char **value)
{
    if (value)
        free(*value);
}

static char *get_result_file_name(char *file_path)
{
    char *suffix = ".cor";
    size_t file_name_length = tablen(file_path, sizeof(char));
    ssize_t index;
    char *result;

    if (!file_name_length)
        return (NULL);
    for (index = file_name_length - 1;
        index >= 0 && file_path[index] != '.'; index--);
    if (index < 0)
        index = file_name_length;
    result = my_malloc(index + 4, sizeof(char));
    if (!result)
        return (NULL);
    for (ssize_t i = 0; i < index; i++)
        result[i] = file_path[i];
    for (size_t i = 0; i < 4; i++)
        result[i + index] = suffix[i];
    return (result);
}

static ssize_t open_source_file(compiler_t *compiler, char *file_path)
{
    if (!compiler || !file_path)
        return (-2);
    compiler->file = fopen(file_path, "r+");
    if (!compiler->file) {
        print_error(file_path, 0, "No such file or directory.");
        return (-1);
    }
    compiler->file_path = file_path;
    return (0);
}

static size_t write_code_dest(compiler_t *compiler, char *file_path)
{
    int fd;

    if (!compiler || !file_path)
        return (-2);
    fd = open(file_path, O_CREAT | O_RDWR, 0666);
    if (fd == -1) {
        print_error(compiler->file_path, 0, "Cant create binary file.");
        return (-1);
    }
    write(fd, &compiler->header, sizeof(struct header_s));
    cw_write_instructions(compiler, fd);
    close(fd);
    return (0);
}

ssize_t compile_file(char *file_path)
{
    compiler_t compiler __attribute__ ((__cleanup__ (free_compiler))) = {0};
    char *file_result_path __attribute__ ((__cleanup__ (free_value))) = NULL;
    ssize_t result;

    if (!file_path)
        return (-1);
    file_result_path = get_result_file_name(file_path);
    if (!file_result_path)
        return (-2);
    result = open_source_file(&compiler, file_path);
    if (result < 0)
        return (result);
    result = cw_compile(&compiler);
    if (result < 0)
        return (result);
    result = write_code_dest(&compiler, file_result_path);
    if (result < 0)
        return (result);
    return (0);
}
