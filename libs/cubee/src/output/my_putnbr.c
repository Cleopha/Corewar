/*
** EPITECH PROJECT, 2019
** C-LIB
** File description:
** print number
*/

#include "output.h"

void my_putnbr(int nb)
{
    if (nb < 0) {
        nb *= -1;
        my_putchar('-');
    }
    if (nb >= 10)
        my_putnbr(nb / 10);
    my_putchar((nb % 10) + 48);
}
