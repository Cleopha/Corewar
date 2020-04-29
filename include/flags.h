/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** flags header file
*/

typedef struct flags_s {
    size_t address;
    struct flags_s *next;
    struct flags_s *prev;
} flags_t;