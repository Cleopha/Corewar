/*
** EPITECH PROJECT, 2020
** error_management.c
** File description:
** Coline SEGURET's error_management.c made the 05/09/2020
*/

#include "corewar.h"
#include "vm_prototypes.h"
#include <string.h>

int is_num(char *str);
int display_error(const char *str);
void attribute_prognumber(param_t *param);

elem_t *add_elem(int n, int a, elem_t *actual);
elem_t *param_list(int n, int a);

static int error_prognumber(char *av, int *index, param_t *param)
{
    int nb_prog = 0;

    if (param->values[PROGNUMBER] == 0) {
        if (!av || is_num(av))
            return (display_error(err[ERR_PROGNUMBER]));
        nb_prog = getnbr(av);
        if (!(1 <= nb_prog && nb_prog <= 4))
            return (display_error(err[ERR_PROGNUMBER]));
        if (param->prog[nb_prog - 1])
            return (display_error(err[ASS_PROGNUMBER]));
        param->values[PROGNUMBER] = nb_prog;
        param->prog[nb_prog - 1] = true;
        *index += 1;
        return (0);
    } else
        return (display_error(err[TM_PROGNUMBER]));
}

static int error_address(char *av, int *index, param_t *param)
{
    int address = 0;

    if (param->values[ADDRESS] == -1) {
        if (!av || is_num(av))
            return (display_error(err[POS_ADRESS]));
        address = getnbr(av);
        param->values[ADDRESS] = address;
        *index += 1;
        return (0);
    } else
        return (display_error(err[TM_ADRESS]));
}

static int error_dump(char *av, int *index, param_t *param)
{
    int dump = 0;

    if (param->values[DUMP] == 0) {
        if (!av || is_num(av))
            return (display_error(err[POS_DUMP]));
        dump = getnbr(av);
        param->values[DUMP] = dump;
        *index += 1;
        return (0);
    } else
        return (display_error(err[TM_DUMP]));
}

static int is_champs(char *av, param_t *param, elem_t **ch)
{
    int fd = open(av, O_RDONLY);

    if (fd < 0)
        return (display_error(err[NOT_OPEN]));
    if (param->values[PROGNUMBER] == 0)
        attribute_prognumber(param);
    if (*ch == NULL)
        *ch = param_list(param->values[0], param->values[1]);
    else
        *ch = add_elem(param->values[0], param->values[1], *ch);
    (*ch)->fd = fd;
    if (header_handling(ch, fd))
        return (1);
    param->values[ADDRESS] = -1;
    param->values[PROGNUMBER] = 0;
    return (0);
}

int loop_error(char **av, param_t *param, elem_t **champs)
{
    for (int i = 1; av[i]; i += 1) {
        if (tabequals(av[i], "-n", sizeof(char))) {
            if (error_prognumber(av[i + 1], &i, param))
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
