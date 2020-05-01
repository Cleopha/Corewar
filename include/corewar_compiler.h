/*
** EPITECH PROJECT, 2020
** CoreWar
** File description:
** main header
*/

#ifndef _COREWAR_COMPILER_H_
#define _COREWAR_COMPILER_H_

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

struct inst_s {
    char *bytes;
    size_t size;
    struct inst_s *next;
};
typedef struct inst_s inst_t;

inst_t *cw_compile(FILE *file);
int write_instructions(inst_t *instructions, const char *filename);
void free_instructions(inst_t **instructions);

#endif
