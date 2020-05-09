/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** champ_struct.h
*/

#ifndef CPE_COREWAR_2019_CHAMP_STRUCT_H
#define CPE_COREWAR_2019_CHAMP_STRUCT_H

#include <glob.h>
#include "corewar_operation.h"
#include <stdbool.h>

typedef struct elem_s {
    int reg[REG_NUMBER];
    size_t instruction_cycles;
    char *name;
    int progNumber;
    int address;
    struct elem_s *next;
    struct elem_s *before;
}elem_t;

typedef enum param_e
{
    PROGNUMBER,
    ADDRESS,
    DUMP,
}param_e;

typedef struct param_s {
    int values[3];
    bool prog[4];
} param_t;

#endif /* !CPE_COREWAR_2019_CHAMP_STRUCT_H */
