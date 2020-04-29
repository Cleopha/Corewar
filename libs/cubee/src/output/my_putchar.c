/*
** EPITECH PROJECT, 2019
** C-LIB
** File description:
** print char
*/

#include <unistd.h>

void my_putchar(char c)
{
    if (!c)
        return;
    write(1, &c, 1);
}
