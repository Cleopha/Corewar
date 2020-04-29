/*
** EPITECH PROJECT, 2019
** C-LIB
** File description:
** C-LIB debug mode
*/

#ifndef _UTIL_LIB_DEBUG_H_
#define _UTIL_LIB_DEBUG_H_

#ifdef DEBUG

#include <stdio.h>

#define LOG(format, ...) printf(format, __VA_ARGS__)
#define DLOG(fd, format, ...) dprintf(fd, format, __VA_ARGS__)

#else

#define LOG(format, ...) ((void) 0)
#define DLOG(fd, format, ...) ((void) 0)

#endif

#endif
