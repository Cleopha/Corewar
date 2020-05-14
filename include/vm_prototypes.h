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
#include "param_struct.h"

/*
** Structure init
*/
vm_t init_vm(void);
param_vm_t init_param(void);

size_t endian_swapper(size_t value, size_t size);
int champs_nbr_hdl(elem_t const *begin);

/*
** Retrieve number to give it to endian conversion
*/

int retrieve_int(unsigned char const buffer[], int idx_buff);
unsigned short retrieve_short(unsigned char const buffer[], int idx);
unsigned int endian_swap_int(unsigned int n);
unsigned short endian_swap_short(unsigned short n);

/*
** Init and fill VM memory
*/

void set_address(elem_t *champ, int nb);
int fill_mem(vm_t *vm, elem_t *champ);
int header_handling(elem_t *champ, int fd);
void fill_params(vm_t *vm, elem_t *champ, unsigned char buffer[], int *i);
void print_mem(vm_t *vm);
int check_memory_zones(elem_t *champ, elem_t *ch);

#endif /* !CPE_COREWAR_2019_VM_PROTOTYPES_H */
