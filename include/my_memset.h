/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** my_memset.h
*/

#ifndef CPE_COREWAR_2019_MY_MEMSET_H
#define CPE_COREWAR_2019_MY_MEMSET_H

#include <stddef.h>

/******************************************************************************
** @author Benjamin R.
** @file my_memset.c
**
** @brief this function fills the first n bytes of the memory pointed to by s
** with the constant byte c.
**
** @param ptr: pointer to fill
** @param c: the constant byte to fill with
** @param n: the number of bytes to fill
**
** @return the pointer s once filled
*******************************************************************************
*/
void *my_memset(void *ptr, int c, size_t n);

#endif /* !CPE_COREWAR_2019_MY_MEMSET_H */