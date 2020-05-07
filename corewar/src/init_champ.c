/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** init_champ.c
*/

#include "champ_struct.h"
#include <stdlib.h>

champ_t *init_champ(void)
{
    champ_t *champ = malloc(sizeof(champ_t));

    champ->prev = NULL;
    for (int i = 0; i < 3; i++) {
        champ->instruction_cycles = 0;
        for (int j = 0; j < 16; j++)
            champ->reg[j] = 0;
        champ->n = 0;
        champ->name = NULL;
        champ->next = malloc(sizeof(champ_t));
        champ->next->prev = champ;
        champ = champ->next;
    }
    champ = champ->prev;
    free(champ->next);
    champ->next = NULL;
    for (; champ->prev; champ = champ->prev);
    return (champ);
}