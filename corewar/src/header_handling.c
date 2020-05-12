/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** header_handling.c
*/

#include <unistd.h>
#include "champ_struct.h"
#include "corewar_operation.h"
#include "vm_prototypes.h"

int header_handling(elem_t *champ, int fd)
{
    struct header_s header;

    if (read(fd, &header, sizeof(struct header_s)) != sizeof(struct header_s))
        return (84);
    header.magic = endian_conversion(header.magic);
    if (header.magic != COREWAR_EXEC_MAGIC)
        return (84);
    champ->header = header;
    return (0);
}