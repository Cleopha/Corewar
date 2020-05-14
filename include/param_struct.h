/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** param_struct.h
*/

#ifndef CPE_COREWAR_2019_PARAM_STRUCT_H
#define CPE_COREWAR_2019_PARAM_STRUCT_H

#include "union.h"

typedef struct param_vm_s {
    union endian en;
    unsigned char bit;
    unsigned int param_len;
    unsigned int len;
    unsigned char *buffer;
} param_vm_t;

#endif /* !CPE_COREWAR_2019_PARAM_STRUCT_H */
