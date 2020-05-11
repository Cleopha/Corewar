/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** endian_conversion.c
*/

#include <stdio.h>

union endian {
    int nb;
    char str[sizeof(int)];
};

int endian_conversion(int nb)
{
    union endian endian_nb;
    char c = 0;

    endian_nb.nb = nb;
    c = endian_nb.str[3];
    endian_nb.str[3] = endian_nb.str[0];
    endian_nb.str[0] = c;
    c = endian_nb.str[2];
    endian_nb.str[2] = endian_nb.str[1];
    endian_nb.str[1] = c;
    return (endian_nb.nb);
}