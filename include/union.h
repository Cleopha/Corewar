/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** union.h
*/

#ifndef CPE_COREWAR_2019_UNION_H
#define CPE_COREWAR_2019_UNION_H

#include <stddef.h>

union endian {
    size_t nb;
    unsigned char str[sizeof(size_t)];
};

#endif /* !CPE_COREWAR_2019_UNION_H */