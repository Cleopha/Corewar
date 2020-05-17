/*
** EPITECH PROJECT, 2019
** C-LIBS
** File description:
** Test my_putnbr function
*/

#include "unit_test.h"

Test(clib_output_putnbr, positive_number)
{
    cr_redirect_stdout();

    my_putnbr(1024);
    cr_assert_stdout_eq_str("1024");
}

Test(clib_output_putnbr, negative_number)
{
    cr_redirect_stdout();

    my_putnbr(-1024);
    cr_assert_stdout_eq_str("-1024");
}
