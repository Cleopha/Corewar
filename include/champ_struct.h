/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** champ_struct.h
*/

#ifndef CPE_COREWAR_2019_CHAMP_STRUCT_H
#define CPE_COREWAR_2019_CHAMP_STRUCT_H

#include <glob.h>

typedef struct champ_s {
    struct champ_s *next;
    struct champ_s *prev;
    int reg[16];
    size_t instruction_cycles;
    char *name;
    int n;
} champ_t;

#endif /* !CPE_COREWAR_2019_CHAMP_STRUCT_H */