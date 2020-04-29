/*
** EPITECH PROJECT, 2019
** C-LIB
** File description:
** free function with check pointer
*/

#include "pointer/allocation.h"

void mcfree(void *value, size_t level, void (*function)(void *))
{
    if (level && value)
        for (size_t i = 0; ((void **) value)[i]; i++)
            mcfree(((void **) value)[i], level - 1, NULL);
    cfree(value, function);
}
