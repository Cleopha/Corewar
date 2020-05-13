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
int fill_mem(vm_t *vm, elem_t *champ);
int retrieve_int(unsigned char const buffer[], int idx_buff);
int check_memory_zones(elem_t *champ, elem_t *ch);
void set_address(elem_t *champ);
int champs_nbr_hdl(elem_t const *begin);

#endif /* !CPE_COREWAR_2019_VM_PROTOTYPES_H */