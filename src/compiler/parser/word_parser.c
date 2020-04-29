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

static ssize_t parse_line(struct instruction_s **instructions, FILE *file)
{
    size_t n = 0;
    char *line = NULL;
    ssize_t size = getline(&line, &n, file);
    char **words;
    char *bytes = NULL;
    size_t bytes_size = 0;

    if (size < 2 || !tabstart(line, "#", sizeof(char)))
        return (size);
    line[size - 1] = 0;
    words = (char **) tabsplit_clean(line, " ", sizeof(char));
    if (!words)
        return (size);
    //bytes_size = the_fucking_coline_function(&bytes, words);
    if (bytes_size < 0)
        return (-2);
    mcfree(words, 1, NULL);
    add_node(instructions, bytes, bytes_size);
    return (size);
}

inst_t *cw_compile(FILE *file)
{
    inst_t *instructions = NULL;

    if (!file)
        return (NULL);
    while (parse_line(&instructions, file) > 0);
    return (instructions);
}