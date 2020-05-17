/*
** EPITECH PROJECT, 2020
** endian_conversion.c
** File description:
** Coline SEGURET's endian_conversion.c made the 05/17/2020
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
