/*
** EPITECH PROJECT, 2020
** error_display
** File description:
** error_display
*/

#include "err_management.h"
#include "champ_struct.h"

char *err[] = {
    "Wrong champions numbers"
    "Prognumber must be between 1 and 4\n",
    "Too much prognumber\n",
    "Prognumber already assigned\n",
    "Address must be a positive number\n",
    "Too much addresses\n",
    "Dump must be a positive number\n",
    "Too much dump\n",
    "Invalid parameter: not a champion\n",
    "Not a champion header\n"
};

int champs_nbr_hdl(elem_t const *begin)
{
    int nb = my_list_size(begin);

    if (nb < 2 && nb > 4) {
        display_error(err[TM_CHAMPIONS]);
        return (84);
    }
}
