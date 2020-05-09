/*
** EPITECH PROJECT, 2020
** error_management.c
** File description:
** Coline SEGURET's error_management.c made the 05/09/2020
*/

#include "corewar.h"

int is_num(char *str);

int error_progNumber(char *av, int *index, param_t *param)
{
    int nbProg = 0;

    if (param->values[PROGNUMBER] == 0) {
        if (!av || is_num(av)) {
            my_putstr_error("prognumber doit etre un nombre entre 1 et 4");
            return (1);
        }
        nbProg = getnbr(av);
        if (0 <= nbProg && nbProg >= 4) {
            my_putstr_error("prognumber doit etre un nombre entre 1 et 4");
            return (1);
        }
        if (param->prog[nbProg]) {
            my_putstr_error("PROGNUMBER DEJA ASSIGNE");
            return (1);
        }
        param->values[PROGNUMBER] = nbProg;
        param->prog[nbProg] = true;
        *index += 1;
        return (0);
    } else {
        my_putstr_error("TROP DE PROGNUMBER");
        return (1);
    }
}

int error_address(char *av, int *index, param_t *param)
{
    int address = 0;

    if (param->values[ADDRESS] == -1) {
        if (!av || is_num(av)) {
            my_putstr_error("adress doit etre un nombre positif");
            return (1);
        }
        address = getnbr(av);
        param->values[ADDRESS] = address;
        *index += 1;
        return (0);
    } else {
        my_putstr_error("TROP D'ADRESS");
        return (1);
    }
}

int error_dump(char *av, int *index, param_t *param)
{
    int dump = 0;

    if (param->values[DUMP] == 0) {
        if (!av || is_num(av)) {
            my_putstr_error("DUMP dois etre positif");
            return (1);
        }
        dump = getnbr(av);
        param->values[DUMP] = dump;
        *index += 1;
        return (0);
    } else {
        my_putstr_error("TROP DE DUMP");
        return (1);
    }
}
