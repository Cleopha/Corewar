/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** vm_prototypes.h
*/

#ifndef CPE_COREWAR_2019_VM_PROTOTYPES_H
#define CPE_COREWAR_2019_VM_PROTOTYPES_H

#include "champ_struct.h"
#include "vm_struct.h"

vm_t init_vm(void);
int endian_conversion(int nb);
int header_handling(elem_t *champ, int fd);
int fill_mem(vm_t *vm, elem_t *champ, int fd);

#endif /* !CPE_COREWAR_2019_VM_PROTOTYPES_H */