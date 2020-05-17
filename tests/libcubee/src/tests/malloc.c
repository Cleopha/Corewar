/*
** EPITECH PROJECT, 2019
** C-LIB
** File description:
** test malloc function
*/

#include "malloc.h"

int malloc_error_test = 0;

void *test_malloc(size_t size)
{
    if (malloc_error_test == -1 || malloc_error_test > 0) {
        malloc_error_test -= (malloc_error_test > 0) ? 1 : 0;
        return (NULL);
    } else if (malloc_error_test < -1)
        malloc_error_test += (malloc_error_test == -2) ? 3 : 1;
    return (__libc_malloc(size));
}

void *malloc(size_t size) __attribute__((alias ("test_malloc")));
