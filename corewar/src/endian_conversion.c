/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** endian_conversion.c
*/

#include "union.h"

int endian_conversion(int nb)
{
    union endian endian;
    char c = 0;

    endian.nb = nb;
    c = endian.str[3];
    endian.str[3] = endian.str[0];
    endian.str[0] = c;
    c = endian.str[2];
    endian.str[2] = endian.str[1];
    endian.str[1] = c;
    return (endian.nb);
}