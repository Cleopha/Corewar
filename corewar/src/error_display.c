/*
** EPITECH PROJECT, 2020
** error_display
** File description:
** error_display
*/

#include "err_management.h"
#include "champ_struct.h"
#include "cubee.h"

const char *err[] = {
    "Wrong champions numbers\n",
    "Prognumber must be between 1 and 4\n",
    "Too much prognumber\n",
    "Prognumber already assigned\n",
    "Address must be a positive number\n",
    "Too much addresses\n",
    "Dump must be a positive number\n",
    "Too much dump\n",
    "Invalid parameter: not a champion\n",
    "Not a champion header\n",
    "Wrong number of champions,\
 the number of champions must be between 2 and 4\n"
};

int display_error(const char *str)
{
    my_putstr_error(str);
    return (1);
}
