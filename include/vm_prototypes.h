/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** vm_prototypes.h
*/

#ifndef CPE_COREWAR_2019_VM_PROTOTYPES_H
#define CPE_COREWAR_2019_VM_PROTOTYPES_H

#include <stdio.h>

#include "champ_struct.h"
#include "vm_struct.h"
#include "param_struct.h"

/*
** Structure init
*/
vm_t init_vm(void);
param_vm_t init_param(void);

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
int header_handling(elem_t **champ, int fd);
void fill_params(vm_t *vm, elem_t *champ, unsigned char buffer[], int *i);
void print_mem(vm_t *vm);
int check_memory_zones(elem_t *champ, elem_t *ch);

/*
** Instructions
*/

int live(vm_t *vm, elem_t *champs);
int ld(vm_t *vm, elem_t *champs);
int st(vm_t *vm, elem_t *champs);
int add(vm_t *vm, elem_t *champs);
int sub(vm_t *vm, elem_t *champs);
int and(vm_t *vm, elem_t *champs);
int or(vm_t *vm, elem_t *champs);
int xor(vm_t *vm, elem_t *champs);
int zjmp(vm_t *vm, elem_t *champs);
int ldi(vm_t *vm, elem_t *champs);
int sti(vm_t *vm, elem_t *champs);
int my_fork(vm_t *vm, elem_t *champs);
int lld(vm_t *vm, elem_t *champs);
int lldi(vm_t *vm, elem_t *champs);
int lfork(vm_t *vm, elem_t *champs);
int aff(vm_t *vm, elem_t *champs);

/*
** Get_params
*/

int get_indirect(vm_t *vm, elem_t *champs);
int get_direct(vm_t *vm, elem_t *champs, int diff);
int get_index_reg(vm_t *vm, elem_t *champs);
void get_param(unsigned char params, int *value_one,
vm_t *vm, elem_t *champs);
void get_param_without_mod(unsigned char params, int *value_one,
vm_t *vm, elem_t *champs);

/*
** set_begin_instruction
*/

void set_param_with_byte(unsigned char coding_byte, unsigned char params[4]);
void set_carry_flag(int nb, elem_t *champs);
void skip_coding_byte(elem_t *champs, vm_t *vm,
unsigned char params[4], int nb_inst);

/*
** Fork functions
*/

void init_forked_prog(elem_t *champs, elem_t *node);
void link_new_node(elem_t *champs, elem_t *node);

/*
** Write params in mem
*/

void ind_write(vm_t *vm, elem_t *champs, int value, int ind);

/*
** Running loop
*/

int loop_vm(vm_t *vm, elem_t *champs);
elem_t *remove_champ(elem_t **champs);

#endif /* !CPE_COREWAR_2019_VM_PROTOTYPES_H */
