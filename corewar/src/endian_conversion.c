/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** endian_conversion.c
*/

#include <glob.h>

size_t endian_swapper(size_t value, size_t size)
{
    size_t result = 0;
    size_t offset = (size - 1) * 8;
    size_t mid = size / 2;
    size_t firs_half = 0xFFu;
    size_t second_half = 0xFFu;

    for (size_t i = 0; i < size; i++)
        second_half *= 0x100;
    for (int i = 0; i < mid; i++) {
        result |= (value & firs_half) << offset;
        result |= (value & second_half) >> offset;
        offset -= 16;
        firs_half *= 0x100;
        second_half /= 0x100;
    }
    return (result);
}

unsigned int endian_swap_int(unsigned int n)
{
    return (((n >> 24u) & 0xFFu) | ((n << 8u) & 0x00FF0000u)
    | ((n >> 8u) & 0xFF00u) | ((n << 24u) & 0xFF000000u));
}

unsigned short endian_swap_short(unsigned short n)
{
    return ((n << 8) | (n >> 8));
}