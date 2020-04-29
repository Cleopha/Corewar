/*
** EPITECH PROJECT, 2019
** MY-CLIB
** File description:
** string edit
*/

#include "pointer/allocation.h"

static void swap_value(size_t *a, size_t *b)
{
    size_t temp = *a;

    *a = *b;
    *b = temp;
}

char *stredit(char const *str, size_t from, size_t to, char const *replace)
{
    size_t str_len = tablen(str, sizeof(char));
    size_t replace_len = tablen(replace, sizeof(char));
    size_t total_len;
    char *result;

    if (from > to)
        swap_value(&from, &to);
    if (!str_len || from > str_len || to > str_len)
        return (NULL);
    total_len = str_len + replace_len - to + from - 1;
    result = my_malloc(total_len, sizeof(char));
    if (!result)
        return (NULL);
    for (size_t i = 0; i < from; i++)
        result[i] = str[i];
    for (size_t i = 0; i < replace_len; i++)
        result[i + from] = replace[i];
    for (size_t i = to; i < str_len; i++)
        result[i + from + replace_len - to] = str[i];
    return (result);
}
