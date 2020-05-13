/*
** EPITECH PROJECT, 2019
** my_put_hexa
** File description:
** change a decimal number into an hexadecimal number
*/

#include <stdlib.h>
#include "put_hexa.h"
#include "cubee.h"

void hexa_fill(uint64_t *nb, uint64_t *hexa_pow, char **hexa_nb, int (*j)[2])
{
    char c;

    if ((*nb) >= (*hexa_pow)) {
        (*nb) -= (*hexa_pow);
        (*hexa_nb)[(*j)[0]] += 1;
        c = (*hexa_nb)[(*j)[0]];
        if (c >= ':' && c <= '?')
            (*hexa_nb)[(*j)[0]] += (*j)[1];
    } else {
        (*hexa_pow) /= 16;
        (*j)[0]++;
    }
}

void my_put_hexa(uint64_t nb, int letter)
{
    int i = 0;
    int j[2] = {0, letter};
    uint64_t hexa_pow = 1;
    char *hexa_nb;

    for (; (hexa_pow * 16) <= nb; i++)
        hexa_pow *= 16;
    hexa_nb = malloc(sizeof(char) * (i + 2));
    for (; j[0] <= i; j[0]++)
        hexa_nb[j[0]] = '0';
    j[0] = 0;
    while (j[0] <= i)
        hexa_fill(&nb, &hexa_pow, &hexa_nb, &j);
    hexa_nb[j[0]] = '\0';
    my_putstr(hexa_nb);
    free(hexa_nb);
}

void my_put_hexa_min(uint64_t nb)
{
    my_put_hexa(nb, LOWERCASE);
}

void my_put_hexa_maj(uint64_t nb)
{
    my_put_hexa(nb, UPPERCASE);
}

void my_put_address(uint64_t nb)
{
    my_putstr("0x");
    my_put_hexa(nb, LOWERCASE);
}