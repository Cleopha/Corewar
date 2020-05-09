/*
** EPITECH PROJECT, 2020
** error_management.c
** File description:
** Coline SEGURET's error_management.c made the 05/09/2020
*/

#include "corewar.h"
#include <string.h> //1 strdup

int is_num(char *str);
int display_error(char *str);

elem_t *add_elem(char *str, int n, int a, elem_t *actual);
elem_t *param_list(char *str, int n, int a);

static int error_progNumber(char *av, int *index, param_t *param)
{
    int nbProg = 0;

    if (param->values[PROGNUMBER] == 0) {
        if (!av || is_num(av))
            return (display_error("prognumber doit etre un nombre entre 1 et 4"));
        nbProg = getnbr(av);
        if (0 <= nbProg && nbProg >= 4)
            return (display_error("prognumber doit etre un nombre entre 1 et 4\n"));
        if (param->prog[nbProg])
            return (display_error("PROGNUMBER DEJA ASSIGNE\n"));
        param->values[PROGNUMBER] = nbProg;
        param->prog[nbProg] = true;
        *index += 1;
        return (0);
    } else
        return (display_error("TROP DE PROGNUMBER\n"));
}

static int error_address(char *av, int *index, param_t *param)
{
    int address = 0;

    if (param->values[ADDRESS] == -1) {
        if (!av || is_num(av))
            return (display_error("adress doit etre un nombre positif\n"));
        address = getnbr(av);
        param->values[ADDRESS] = address;
        *index += 1;
        return (0);
    } else
        return (display_error("TROP D'ADRESS\n"));
}

static int error_dump(char *av, int *index, param_t *param)
{
    int dump = 0;

    if (param->values[DUMP] == 0) {
        if (!av || is_num(av))
            return (display_error("DUMP dois etre positif\n"));
        dump = getnbr(av);
        param->values[DUMP] = dump;
        *index += 1;
        return (0);
    } else
        return (display_error("TROP DE DUMP\n"));
}

static int is_champs(char *av, param_t *param, elem_t **ch)
{
    FILE *fd = fopen(av, "r+");
    char *buffer = 0;
    size_t len = 0;

    if (fd == NULL)
        return (display_error("OUVREPAS\n"));
    if (getline(&buffer, &len, fd) == - 1)
        return (display_error("PAS UN HEADER CHAMPION\n"));
    if (*ch == NULL)
        *ch = param_list(strdup(av), param->values[0], param->values[1]);
    else
        *ch = add_elem(strdup(av), param->values[0], param->values[1], *ch);
    param->values[ADDRESS] = -1;
    param->values[PROGNUMBER] = 0;
    return (0);
}

int loop_error(char **av, param_t *param, elem_t **champs)
{
    for (int i = 1; av[i]; i += 1) {
        if (tabequals(av[i], "-n", sizeof(char))) {
            if (error_progNumber(av[i + 1], &i, param))
                return (1);
            continue;
        }
        if (tabequals(av[i], "-a", sizeof(char))) {
            if (error_address(av[i + 1], &i, param))
                return (1);
            continue;
        }
        if (tabequals(av[i], "-dump", sizeof(char))) {
            if (error_dump(av[i + 1], &i, param))
                return (1);
            continue;
        }
        if (is_champs(av[i], param, champs))
            return (1);
    }
    return (0);
}
