/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** retrieve_int.c
*/

unsigned int retrieve_int(unsigned char const buffer[], int idx_buf)
{
    unsigned int index = 0;
    unsigned int re = 0;

    for (; index < 3; index += 1) {
        re |= buffer[idx_buf + index];
        re <<= 8u;
    }
    re |= buffer[idx_buf + index];
    return (re);
}

unsigned short retrieve_short(unsigned char const buffer[], int idx)
{
    unsigned int index = 0;
    unsigned short res = 0;

    res |= buffer[idx + index];
    res <<= 8u;
    index += 1;
    res |= buffer[idx + index];
    return (res);
}