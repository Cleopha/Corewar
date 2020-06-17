#!/usr/bin/env bash
##
## EPITECH PROJECT, 2020
## script.sh
## File description:
## Coline SEGURET's script.sh made the 05/17/2020
##

tester()
{
./tests/asm tests/$1.s
mv $1.cor real_$1.cor
./asm tests/$1.s
mv tests/$1.cor .
hexdump -C $1.cor > $1.txt
hexdump -C real_$1.cor > real_$1.txt
echo -e "\033[92m---"$1"---\033[0m"
diff $1.txt real_$1.txt
echo -e "\033[91m---end---\033[0m"
rm *.txt
rm *.cor
}
tester "42"
tester "aurollan"
tester "cepalle2"
tester "ex"
tester "jumper"
tester "mortel"
tester "slider2"
tester "toto"
tester "abel"
tester "barriere"
tester "cepalle"
tester "gagnant"
tester "kroz"
tester "ppichier"
tester "sujet"
tester "tyron"
tester "air_max"
tester "car"
tester "corruption"
tester "maxi_def"
tester "rouge"
tester "zob"
tester "pdd"
