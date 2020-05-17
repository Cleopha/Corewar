/*
** EPITECH PROJECT, 2019
** C-LIBS
** File description:
** Test my_putstr_error function
*/

#include "unit_test.h"

Test(clib_output_putstr_error, normal_test)
{
    cr_redirect_stderr();

    my_putstr_error("Hello World !");
    cr_assert_stderr_eq_str("Hello World !");
}

Test(clib_output_putstr_error, null_value)
{
    cr_redirect_stderr();

    my_putstr_error(NULL);
    cr_assert_stderr_neq_str("Hello World !");
}
