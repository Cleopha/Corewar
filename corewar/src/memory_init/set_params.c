/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** set_params.c
*/

#include "vm_prototypes.h"

void direct_param(unsigned char const buffer[], vm_t *vm, unsigned int i,
                    param_vm_t *param)
{
    if (vm->dir_size == 4)
        param->en.nb = endian_swap_int(retrieve_int(buffer, i));
    else
        param->en.nb = endian_swap_short(retrieve_short(buffer, i));
}

void check_param(vm_t *vm, elem_t *champ, unsigned int i, param_vm_t *param)
{
    if (param->bit == 0b01) {
        param->param_len = 1;
        vm->mem[champ->address + i] = param->buffer[i];
    } else if (param->bit == 0b10) {
        param->param_len = vm->dir_size;
        direct_param(param->buffer, vm, i, param);
    } else {
        param->param_len = IND_SIZE;
        param->en.nb = endian_swap_short(retrieve_short(param->buffer, i));
    }
}

void fill_params(vm_t *vm, elem_t *champ, unsigned char buffer[],
                    unsigned int *i)
{
    param_vm_t param = init_param();

    param.buffer = buffer;
    for (unsigned int j = 0; j < 3; j++) {
        param.bit = (buffer[*i] >> ((j * 2 - 6) * -1)) & 0b11;
        if (param.bit != 0b00)
            check_param(vm, champ, *i + param.len, &param);
        else
            break;
        for (int k = 0; param.param_len != 1 && k < param.param_len; k++)
            vm->mem[champ->address + *i + k + param.len] = param.en.str[k];
        param.len += param.param_len;
    }
    *i += param.len;
}