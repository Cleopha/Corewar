/*
** EPITECH PROJECT, 2019
** C-LIB
** File description:
** C-LIB allocation header
*/

#ifndef _UTIL_LIB_ALLOCATION_H_
#define _UTIL_LIB_ALLOCATION_H_

#include <stdlib.h>

typedef char byte;

size_t tablen(void const *element, size_t unit);
void *my_malloc(size_t number, size_t unit);
void *my_init_malloc(size_t number, size_t unit);
void cfree(void *value, void (*function)(void *));
void mcfree(void *value, size_t level, void (*function)(void *));

#endif
