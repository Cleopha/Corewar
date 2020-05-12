/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** retrieve_int.c
*/

unsigned int retrieve_int(char *buffer, int idx_buf)
{
    unsigned int index = 0;
    unsigned int re = 0;

    for (; index < 3; index += 1) {
        re |= buffer[idx_buf + index];
        re <<= 8;
    }
    re |= buffer[idx_buf + index];
    return (re);
}