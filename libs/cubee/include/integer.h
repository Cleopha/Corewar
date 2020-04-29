/*
** EPITECH PROJECT, 2019
** C-LIB
** File description:
** C-LIB output header
*/

#ifndef _UTIL_LIB_INTEGER_H_
#define _UTIL_LIB_INTEGER_H_

#include <stdint.h>

#include "pointer.h"

int getnbr(char const *str);
char *ntoa(intmax_t nbr, const char *base, char signed_nbr);

#endif
