/*
** EPITECH PROJECT, 2020
** CoreWar
** File description:
** operations
*/

#include "corewar_operation.h"

op_t op_tab[23] = {
    {3322092, "live", 1, {T_DIR}, 1, 10, "alive"},
    {3448, "ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load"},
    {3681, "st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store"},
    {96417, "add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition"},
    {114240, "sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction"},
    {96727, "and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6,
    6, "et (and  r1, r2, r3   r1&r2 -> r3"},
    {3555, "or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7,
    6, "ou  (or   r1, r2, r3   r1 | r2 -> r3"},
    {118875, "xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
    8, 6, "ou (xor  r1, r2, r3   r1^r2 -> r3"},
    {3739859, "zjmp", 1, {T_DIR}, 9, 20, "jump if zero"},
    {106993, "ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
    "load index"},
    {114216, "sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
    "store index"},
    {3148994, "fork", 1, {T_DIR}, 12, 800, "fork"},
    {107236, "lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load"},
    {3324421, "lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
    "long load index"},
    {102889262, "lfork", 1, {T_DIR}, 15, 1000, "long fork"},
    {96481, "aff", 1, {T_REG}, 16, 2, "aff"},
    {0, 0, 0, {0}, 0, 0, 0}};