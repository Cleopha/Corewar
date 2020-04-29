/*
** EPITECH PROJECT, 2019
** C-LIB
** File description:
** free function with check pointer
*/

#include <stdlib.h>

void cfree(void *value, void (*function)(void *))
{
    if (value) {
        if (function)
            function(value);
        else
            free(value);
    }
}
