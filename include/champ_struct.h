/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** champ_struct.h
*/

#ifndef CPE_COREWAR_2019_CHAMP_STRUCT_H
#define CPE_COREWAR_2019_CHAMP_STRUCT_H

#include <stddef.h>
#include <stdbool.h>
#include "corewar_operation.h"
#include "err_management.h"

typedef struct elem_s {
    size_t instruction_cycles;
    int reg[REG_NUMBER];
    int prog_number;
    int address;
    int fd;
    bool is_alive;
    int pc;
    struct header_s header;
    struct elem_s *next;
    struct elem_s *prev;
}elem_t;

enum param_e {
    PROGNUMBER,
    ADDRESS,
    DUMP,
};

typedef struct param_s {
    int values[3];
    bool prog[4];
} param_t;

#endif /* !CPE_COREWAR_2019_CHAMP_STRUCT_H */
