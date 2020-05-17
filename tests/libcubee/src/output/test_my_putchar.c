/*
** EPITECH PROJECT, 2019
** C-LIBS
** File description:
** Test my_putchar function
*/

#include "unit_test.h"

Test(clib_output_putchar, normal_test)
{
    cr_redirect_stdout();

    my_putchar('T');
    cr_assert_stdout_eq_str("T");
}

Test(clib_output_putchar, zero_value)
{
    cr_redirect_stdout();

    my_putchar('\0');
    cr_assert_stdout_neq_str("T");
}
