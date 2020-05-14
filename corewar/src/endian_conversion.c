/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** endian_conversion.c
*/

#include <glob.h>

unsigned int endian_swap_int(unsigned int n)
{
    return (((n >> 24u) & 0xFFu) | ((n << 8u) & 0x00FF0000u)
    | ((n >> 8u) & 0xFF00u) | ((n << 24u) & 0xFF000000u));
}

unsigned short endian_swap_short(unsigned short n)
{
    return ((n << 8) | (n >> 8));
}
