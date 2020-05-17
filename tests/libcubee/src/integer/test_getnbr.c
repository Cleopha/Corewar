/*
** EPITECH PROJECT, 2019
** C-LIB
** File description:
** test getnbr function
*/

#include "unit_test.h"

Test(clib_integer_getnbr, normal_test)
{
    cr_assert_eq(getnbr("123"), 123);
}

Test(clib_integer_getnbr, signs_test_positive)
{
    cr_assert_eq(getnbr("---+++++++-++++++++--++--123"), 123);
}

Test(clib_integer_getnbr, signs_test_negative)
{
    cr_assert_eq(getnbr("--a---+++++++-++++++++---++--123"), -123);
}

Test(clib_integer_getnbr, overflow_test_1)
{
    cr_assert_eq(getnbr("123456789987654321"), 0);
}

Test(clib_integer_getnbr, overflow_test_2)
{
    cr_assert_eq(getnbr("2147483648"), 0);
}

Test(clib_integer_getnbr, null_value)
{
    cr_assert_eq(getnbr(NULL), 0);
}

Test(clib_integer_getnbr, parsing_test)
{
    cr_assert_eq(getnbr("/--+++a+++-++++---++--aer+-+-+-123:toto-"), -123);
}

Test(clib_integer_getnbr, parsing_test_2)
{
    cr_assert_eq(getnbr("/--+++a+++-++++---++--aer++-+-123-toto-"), 123);
}
