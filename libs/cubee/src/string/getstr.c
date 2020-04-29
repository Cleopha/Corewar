/*
** EPITECH PROJECT, 2019
** C-LIB
** File description:
** get string
*/

#include "pointer/allocation.h"

static void swap_value(size_t *a, size_t *b)
{
    size_t temp = *a;

    *a = *b;
    *b = temp;
}

char *getstr(char const *str, size_t from, size_t to)
{
    size_t str_len = tablen(str, sizeof(char));
    size_t new_len;
    char *result;

    if (from > to)
        swap_value(&from, &to);
    if (!str_len || from > str_len || to > str_len)
        return (NULL);
    new_len = to - from + 1;
    result = my_malloc(new_len, sizeof(char));
    if (!result)
        return (NULL);
    for (size_t i = 0; i < new_len; i++)
        result[i] = str[i + from];
    return (result);
}
