/*
** EPITECH PROJECT, 2019
** C-LIBS
** File description:
** Test my_putstr function
*/

#include "unit_test.h"

Test(clib_output_putstr, normal_test)
{
    cr_redirect_stdout();

    my_putstr("Hello World !");
    cr_assert_stdout_eq_str("Hello World !");
}

Test(clib_output_putstr, null_value)
{
    cr_redirect_stdout();

    my_putstr(NULL);
    cr_assert_stdout_neq_str("Hello World !");
}
