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

#include "corewar_operation.h"
#include "corewar_util.h"
#include "cubee.h"

struct flag_s {
    size_t hash;
    size_t location;
    struct flag_s *next;
};
typedef struct flag_s flag_t;

struct inst_s {
    char *bytes;
    size_t size;
    struct inst_s *next;
};
typedef struct inst_s inst_t;

struct flag_queue_s {
    size_t hash;
    size_t location;
    size_t line;
    char *flag_inst_ptr;
};
typedef struct flag_queue_s flag_queue_t;

struct compiler_s {
    char *file_path;
    FILE  *file;
    size_t current_byte;
    size_t current_line;
    flag_t *flags;
    inst_t *instructions;
};
typedef struct compiler_s compiler_t;

ssize_t cw_flags_location(compiler_t *compiler, char *flag);
int cw_flags_register(compiler_t *compiler, char *flag, size_t loc);
int wc_flags_compile(compiler_t *compiler, char *flag, char *bytes,
    size_t size);
void cw_flags_clear(compiler_t *compiler);

ssize_t cw_compile_instruction(compiler_t *compiler, char **bytes,
    char **words);
int cw_compile(compiler_t *compiler);
int write_instructions(compiler_t *compiler, const char *filename);
void free_compiler(compiler_t *compiler);

void print_error(const char *file, size_t line, const char *msg);
void print_compiler_error(compiler_t *compiler, const char *msg);

#endif
