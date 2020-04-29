/*
** EPITECH PROJECT, 2019
** C-LIB
** File description:
** C-LIB allocation header
*/

#ifndef _UTIL_LIB_POINTER_H_
#define _UTIL_LIB_POINTER_H_

#include <stdint.h>

#include "pointer/allocation.h"

void *tabcat(const void *tab1, const void *tab2, size_t unit);
size_t tabcount(const void *tab, const void *search, size_t unit);
void *tabdump(const void *tab, size_t unit);
void *mtabdump(const void *tab, size_t unit, size_t level);
int32_t tabequals(const void *tab1, const void *tab2, size_t unit);
size_t tablen(const void *element, size_t unit);
int32_t tabstart(const void *tab, const void *start, size_t unit);
int tabend(const void *tab, const void *end, size_t unit);
void *tabfindptr(const void *tab, const void *search, size_t unit);
ssize_t tabfind(const void *tab, const void *search, size_t unit);
void **tabsplit(const void *data, const void *split, size_t unit, size_t *size);
void **tabsplit_clean(const void *data, const void *split, size_t unit);
char tab_isnull(const void *tab, size_t unit);

#endif
