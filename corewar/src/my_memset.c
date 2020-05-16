/*
** EPITECH PROJECT, 2019
** memset
** File description:
** BISTRO
*/

#include "my_memset.h"

void *my_memset(void *ptr, int c, size_t n)
{
    char *str = (char *)ptr;

    for (size_t i = 0; i < n; i++)
        str[i] = c;
    return (str);
}