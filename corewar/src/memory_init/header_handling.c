/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** header_handling.c
*/

#include <unistd.h>
#include "cubee.h"
#include "champ_struct.h"
#include "corewar_operation.h"
#include "vm_prototypes.h"

int header_handling(elem_t **champ, int fd)
{
    struct header_s header;

    if (read(fd, &header, sizeof(struct header_s)) != sizeof(struct header_s)) {
        my_putstr_error("Invalid header\n");
        return (1);
    }
    header.magic = endian_swap_int(header.magic);
    if (header.magic != COREWAR_EXEC_MAGIC) {
        my_putstr_error("Magic value missing\n");
        return (1);
    }
    header.prog_size = endian_swap_int(header.prog_size);
    (*champ)->header = header;
    return (0);
}