/*
** EPITECH PROJECT, 2020
** CoreWar
** File description:
** Compiler value writer with inv endian.
*/

#include "corewar_compiler.h"

void cw_write_inv_endian(char *buff, char *value, size_t size)
{
    if (!buff || !value || !size)
        return;
    for (size_t i = 0; i < size; i++)
        buff[i] = value[size - i - 1];
}