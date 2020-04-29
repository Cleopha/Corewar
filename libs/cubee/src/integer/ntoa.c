/*
** EPITECH PROJECT, 2019
** C-LIB
** File description:
** number to string
*/

#include "integer.h"

static size_t number_length(uintmax_t nbr, size_t base_len)
{
    size_t length = 1;

    for (nbr /= base_len; nbr > 0; length++)
        nbr /= base_len;
    return (length);
}

static void fill_buffer(char *result, uintmax_t nbr, const char *base,
    size_t base_len)
{
    if (nbr >= base_len)
        fill_buffer(result - 1, nbr / base_len, base, base_len);
    *result = base[nbr % base_len];
}

char *ntoa(intmax_t nbr, const char *base, char signed_nbr)
{
    char negative = nbr < 0 && signed_nbr;
    size_t base_len = tablen(base, sizeof(char));
    size_t nbr_len;
    char *result;

    if (!base_len)
        return (NULL);
    if (negative)
        nbr *= -1;
    nbr_len = number_length(nbr, base_len);
    result = my_malloc(nbr_len, sizeof(char));
    if (!result)
        return (NULL);
    if (negative)
        result[0] = '-';
    fill_buffer(result + nbr_len + negative - 1, nbr, base, base_len);
    return (result);
}
