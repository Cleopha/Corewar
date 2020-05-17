/*
** EPITECH PROJECT, 2020
** CoreWar
** File description:
** instruction list manager
*/

#include "corewar_compiler.h"

int cw_add_instruction(compiler_t *compiler, char *bytes, size_t size)
{
    inst_t *instruction;

    if (!compiler || !bytes || !size)
        return (-2);
    instruction = malloc(sizeof(inst_t));
    if (!instruction)
        return (-2);
    *instruction = (inst_t) {bytes, size, compiler->instructions, NULL};
    if (compiler->instructions) {
        instruction->before = compiler->instructions->before;
        if (instruction->before)
            instruction->before->next = instruction;
        compiler->instructions->before = instruction;
    } else {
        instruction->next = instruction;
        instruction->before = instruction;
        compiler->instructions = instruction;
    }
    return (0);
}

ssize_t cw_write_instructions(compiler_t *compiler, int fd)
{
    inst_t *inst = compiler->instructions;
    inst_t *first = inst;
    size_t total_write = 0;

    if (fd == -1)
        return (-1);
    while (inst) {
        write(fd, inst->bytes, inst->size);
        total_write += inst->size;
        inst = (inst->next == first) ? NULL : inst->next;
    }
    return (total_write);
}