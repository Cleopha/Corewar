/*
** EPITECH PROJECT, 2019
** C-LIB
** File description:
** print error string
*/

#include <unistd.h>

#include "pointer/allocation.h"

void my_putstr_error(char const *str)
{
    size_t str_len = tablen(str, sizeof(char));

    if (!str_len)
        return;
    write(2, str, str_len);
}
