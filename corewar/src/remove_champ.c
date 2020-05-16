/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** remove_champ.c
*/

#include <stdlib.h>
#include "champ_struct.h"

void remove_champ(elem_t **champs)
{
    elem_t *copy = *champs;

    if ((*champs) == NULL)
        return;
    if (copy->next)
        copy->next->prev = copy->prev;
    if (copy->prev)
        copy->prev->next = copy->next;
    if (copy->prev)
        (*champs) = copy->prev;
    else if (copy->next)
        (*champs) = copy->next;
    else
        (*champs) = NULL;
    free (copy);
    copy = NULL;
}