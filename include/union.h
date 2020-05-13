/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** union.h
*/

#ifndef CPE_COREWAR_2019_UNION_H
#define CPE_COREWAR_2019_UNION_H

union endian {
    int nb;
    char str[sizeof(int)];
};

#endif /* !CPE_COREWAR_2019_UNION_H */