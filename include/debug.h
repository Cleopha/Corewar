/*
** EPITECH PROJECT, 2020
** CoreWar
** File description:
** main header
*/

#ifndef _COREWAR_DEBUG_H_
#define _COREWAR_DEBUG_H_
#ifdef DEBUG

#include <stdio.h>

#define LOG(format, ...) printf(format, __VA_ARGS__)

#else

#define LOG(format, ...) ((void) 0)

#endif
#endif
