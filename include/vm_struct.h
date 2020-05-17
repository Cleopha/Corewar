/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** vm_struct.h
*/

#ifndef CPE_COREWAR_2019_VM_STRUCT_H
#define CPE_COREWAR_2019_VM_STRUCT_H

#include <stddef.h>
#include <stdbool.h>
#include "corewar_operation.h"

enum dir {
    DIR_SHORT,
    DIR_INT,
};

enum coding_byte {
    REG = 1,
    DIR,
    IND
};

typedef struct vm_s {
    unsigned char mem[MEM_SIZE];
    bool is_alive[4];
    char dir_size;
    int nb_prog;
    int dump;
    size_t nb_live;
    size_t cycles_to_die;
} vm_t;

#endif /* !CPE_COREWAR_2019_VM_STRUCT_H */
