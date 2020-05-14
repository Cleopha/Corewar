/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** vm_struct.h
*/

#ifndef CPE_COREWAR_2019_VM_STRUCT_H
#define CPE_COREWAR_2019_VM_STRUCT_H

#include <stddef.h>
#include "corewar_operation.h"

typedef struct vm_s {
    unsigned char mem[MEM_SIZE];
    char dir_size;
    size_t nb_live;
    size_t cycles_to_die;
    size_t cycle_decrease;
} vm_t;

#endif /* !CPE_COREWAR_2019_VM_STRUCT_H */