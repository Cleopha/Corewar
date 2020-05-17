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

#define GET_DIRECT_SIZE(code) (((code >= 9 && code <= 12) \
    || code == 14 || code == 15) ? 2 : 4)
#define IS_PARAM_BYTE(c) (c != 1 && c != 9 && c != 12 && c != 15)
#define PRINT_ERROR(msg) (print_error(NULL, 0, msg))

/*
* Flag struct contains:
* - hash (hash of it name) for identify it.
* - Location for find out where it is.
*/
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
    struct inst_s *before;
};
typedef struct inst_s inst_t;

/*
* Flag queue struct contains:
* - hash (hash of it name) for identify it.
* - Location for find out where it is.
* - Line for find out where it is in source code.
* - Flag pointer point to where it should be written.
*/
struct flag_queue_s {
    size_t hash;
    size_t location;
    size_t line;
    char *flag_ptr;
    op_t *instruction;
    struct flag_queue_s *before;
    struct flag_queue_s *next;
};
typedef struct flag_queue_s flag_queue_t;

/*
* Compiler struct contains all util elements for compilation
* and error management .
*/
struct compiler_s {
    char *file_path;
    FILE  *file;
    struct header_s header;
    char header_complete;
    size_t current_byte;
    size_t current_line;
    op_t *current_inst;
    flag_t *flags;
    flag_queue_t *flags_queue;
    inst_t *instructions;
};
typedef struct compiler_s compiler_t;

void cw_write_inv_endian(char *buff, char *value, size_t size);

/*
* Function to manage compiled instruction list.
*/
int cw_add_instruction(compiler_t *compiler, char *bytes, size_t size);
ssize_t cw_write_instructions(compiler_t *compiler, int fd);

/*
* Function to manage flag management.
*/
ssize_t cw_flags_location(compiler_t *compiler, char *flag);
int cw_flags_register(compiler_t *compiler, char *flag, size_t loc);
int cw_flags_compile(compiler_t *compiler, char *flag, char *bytes);
void cw_flags_clear(compiler_t *compiler);

/*
* Functions for manage flag queue.
*/
int cw_flags_queue_compile(compiler_t *compiler, char *flags);
int cw_flags_queue_register(compiler_t *compiler, char *flag, size_t loc,
    char *flag_ptr);
void cw_flags_queue_clear(compiler_t *compiler);

/*
* Functions for check instructions params.
*/
ssize_t direct_checker(compiler_t *compiler, char type, const char *word);
ssize_t register_checker(compiler_t *compiler, char type, const char *word);
ssize_t indirect_checker(compiler_t *compiler, char type, const char *word);

/*
* Functions for compile instruction.
*/
// error coding style
ssize_t cw_compile_instruction_param(compiler_t *compiler, char **bytes,
    char **words);
ssize_t cw_compile_instruction(compiler_t *compiler, char **bytes,
    char **words);
ssize_t cw_parse_header(compiler_t *compiler, char *line);
ssize_t cw_compile(compiler_t *compiler);
void free_compiler(compiler_t *compiler);

/*
* Functions for display error.
*/
void print_error(const char *file, size_t line, const char *msg);
void print_compiler_error(compiler_t *compiler, const char *msg);

/*
* Function for compile source code in file.
*/
ssize_t compile_file(char *file_path);

#endif