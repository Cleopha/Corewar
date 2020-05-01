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

static ssize_t parse_instruction(inst_t **instructions, const char *line)
{
    char *bytes = NULL;
    ssize_t bytes_size = 0;
    char **words = (char **) tabsplit_clean(line, " ", sizeof(char));

    if (!words)
        return (0);
    //bytes_size = the_fucking_coline_function(&bytes, words);
    mcfree(words, 1, NULL);
    add_node(instructions, bytes, bytes_size);
    return ((bytes_size < 0) ? -2 : bytes_size);
}

static ssize_t parse_line(inst_t **instructions, FILE *file)
{
    size_t n = 0;
    char *line = NULL;
    ssize_t size = getline(&line, &n, file);
    ssize_t bytes_size = 0;

    if (size < 2 || tabstart(line, "#", sizeof(char))
        || tabstart(line, ".", sizeof(char)))
        return (0);
    line[size - 1] = 0;
    for (ssize_t i = 0; i < size; i++)
        if (line[i] == ',')
            line[i] = ' ';
    bytes_size = parse_instruction(instructions, line);
    free(line);
    return (bytes_size);
}

inst_t *cw_compile(FILE *file)
{
    inst_t *instructions = NULL;

    if (!file)
        return (NULL);
    while (parse_line(&instructions, file) >= 0);
    return (instructions);
}