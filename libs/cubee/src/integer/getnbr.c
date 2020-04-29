/*
** EPITECH PROJECT, 2019
** C-LIB
** File description:
** my get number
*/

#include <unistd.h>

static int my_atoi(char const *str, size_t nb_length)
{
    int pow = 1;
    long result = 0;

    if (nb_length > 10)
        return (0);
    for (size_t i = 0; i < nb_length; i++, pow*= 10) {
        result += (str[-i] - 48) * pow;
        if (result > 2147483647)
            return (0);
    }
    return (result);
}

int getnbr(char const *str)
{
    int length = 0;
    int negative = 0;
    size_t i;

    for (i = 0; str && str[i]; i++) {
        if (!length && str[i] != '+' && str[i] != '-'
            && (str[i] > '9' || str[i] < '0'))
            negative = 0;
        if (((length > 0 && str[i] >= '0') || str[i] >= '1') && str[i] <= '9')
            length++;
        else if (length > 0)
            return my_atoi(str + i - 1, length) * ((negative) ? -1 : 1);
        if (str[i] == '-')
            negative = !negative;
    }
    if (length > 0)
        return my_atoi(str + i - 1, length) * ((negative) ? -1 : 1);
    return (0);
}
