/*
** EPITECH PROJECT, 2019
** C-LIB
** File description:
** split
*/

#include "pointer.h"
#include "string.h"

struct split_s {
    const void *data;
    size_t data_len;
    const void *split;
    size_t split_len;
};

static size_t count_not_null_element(void **data, const size_t size)
{
    size_t result = 0;

    for (size_t i = 0; i < size; i++)
        if (data[i])
            result++;
    return (result);
}

static void *stabdump(const void *tab, size_t length, size_t unit)
{
    size_t total_len = length * unit;
    char *result;

    result = my_malloc(length, unit);
    if (!result)
        return (NULL);
    for (size_t i = 0; i < total_len; i++)
        result[i] = ((char *) tab)[i];
    return (result);
}

static void fill_tab(void **result, size_t length, struct split_s *split,
    size_t unit)
{
    size_t old_pos = 0;
    ssize_t pos;

    for (size_t i = 0; i < length; i++) {
        pos = tabfind(split->data + (old_pos * unit), split->split, unit);
        if (pos > 0)
            result[i] = stabdump(split->data + (old_pos * unit), pos, unit);
        else if (pos < 0)
            result[i] = stabdump(split->data + (old_pos * unit),
                split->data_len - old_pos, unit);
        else
            result[i] = NULL;
        old_pos += pos + split->split_len;
    }
}

void **tabsplit(const void *data, const void *split, size_t unit, size_t *size)
{
    struct split_s split_data = {data, tablen(data, unit),
        split, tablen(split, unit)};
    size_t length = tabcount(data, split, unit) + 1;
    void **result;

    if (!split_data.data_len || !split_data.split_len || !size)
        return (NULL);
    result = malloc(length * sizeof(void *));
    if (!result)
        return (NULL);
    fill_tab(result, length, &split_data, unit);
    *size = length;
    return (result);
}

void **tabsplit_clean(const void *data, const void *split, size_t unit)
{
    size_t size = 0;
    size_t null = 0;
    void **split_result = tabsplit(data, split, unit, &size);
    void **result;

    if (!split_result)
        return (NULL);
    size *= unit;
    null = count_not_null_element(split_result, size);
    result = my_malloc(null, sizeof(void *));
    null = 0;
    for (size_t i = 0; i < size; i++) {
        if (split_result[i])
            result[i - null] = split_result[i];
        else
            null++;
    }
    cfree(split_result, NULL);
    return (result);
}
