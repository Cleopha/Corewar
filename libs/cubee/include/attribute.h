/*
** EPITECH PROJECT, 2019
** C-LIB
** File description:
** attributes
*/

#ifndef UTIL_LIB_ATTRIBUTE_H_
#define UTIL_LIB_ATTRIBUTE_H_

#define DEFAULT __attribute__ ((visibility ("default")))
#define HIDDEN __attribute__ ((visibility ("hidden")))
#define INTERNAL __attribute__ ((visibility ("internal")))
#define PROECTED __attribute__ ((visibility ("protected")))

#define CLEAN_UP(function) __attribute__ ((cleanup(function)))
#define CONSTRUCTOR(function) __attribute__ ((constructor))
#define DESTRUCTOR(function) __attribute__ ((destructor))

#endif
