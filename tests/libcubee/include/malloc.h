/*
** EPITECH PROJECT, 2019
** C-LIB
** File description:
** unit test malloc
*/

#ifndef _CLIB_UNIT_TEST_MALLOC_
#define _CLIB_UNIT_TEST_MALLOC_

#include <stdlib.h>

extern int malloc_error_test;

void *__libc_malloc(size_t size);
void *test_malloc(size_t size);

#endif
