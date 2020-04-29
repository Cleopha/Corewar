/*
** EPITECH PROJECT, 2019
** C-LIB
** File description:
** print string
*/

#include <unistd.h>

#include "pointer/allocation.h"

void my_putstr(char const *str)
{
    size_t str_len = tablen(str, sizeof(char));

    if (str_len)
        write(1, str, str_len);
}
