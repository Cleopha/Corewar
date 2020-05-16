/*
** EPITECH PROJECT, 2020
** CoreWar
** File description:
** main header
*/

#ifndef _COREWAR_OPERATION_H_
#define _COREWAR_OPERATION_H_

#ifndef COREWAR_EXEC_MAGIC
#define COREWAR_EXEC_MAGIC 0xea83f3
#endif

#ifndef PROG_NAME_LENGTH
#define PROG_NAME_LENGTH 128
#endif

#ifndef COMMENT_LENGTH
#define COMMENT_LENGTH 2048
#endif

#ifndef MEM_SIZE
#define MEM_SIZE (6 * 1024)
#endif

#ifndef IDX_MOD
#define IDX_MOD 512
#endif

#ifndef MAX_ARGS_NUMBER
#define MAX_ARGS_NUMBER 4
#endif

#ifndef COMMENT_CHAR
#define COMMENT_CHAR '#'
#endif

#ifndef LABEL_CHAR
#define LABEL_CHAR ':'
#endif

#ifndef DIRECT_CHAR
#define DIRECT_CHAR '%'
#endif

#ifndef SEPARATOR_CHAR
#define SEPERATOR_CHAR ','
#endif

#ifndef LABEL_CHARS
#define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"
#endif

#ifndef NAME_CMD_STRING
#define NAME_CMD_STRING ".name"
#endif

#ifndef COMMENT_CMD_STRING
#define COMMENT_CMD_STRING ".comment"
#endif

#ifndef REG_NUMBER
#define REG_NUMBER 16
#endif

#ifndef T_REG
#define T_REG 1
#endif

#ifndef T_DIR
#define T_DIR 2
#endif

#ifndef T_IND
#define T_IND 4
#endif

#ifndef T_LAB
#define T_LAB 8
#endif

#ifndef IND_SIZE
#define IND_SIZE 2
#endif

#ifndef DIR_SIZE
#define DIR_SIZE 4
#endif

#ifndef REG_SIZE
#define REG_SIZE DIR_SIZE
#endif

#ifndef CYCLE_TO_DIE
#define CYCLE_TO_DIE 1536
#endif

#ifndef CYCLE_DELTA
#define CYCLE_DELTA 5
#endif

#ifndef NBR_LIVE
#define NBR_LIVE 40
#endif

#ifndef COREWAR_EXEC_MAGIC
#define COREWAR_EXEC_MAGIC 0xea83f3
#endif

struct op_s {
    unsigned int hash;
    char *mnemonique;
    char nbr_args;
    char type[MAX_ARGS_NUMBER];
    char code;
    int nbr_cycles;
    char *comment;
};
typedef struct op_s op_t;

struct header_s
{
    int magic;
    char prog_name[PROG_NAME_LENGTH + 1];
    int prog_size;
    char comment[COMMENT_LENGTH + 1];
};

extern op_t op_tab[23];

#endif
