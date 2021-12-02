##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Coline SEGURET's Makefile made the 05/07/2020
##

MAKEFLAGS	+=	--no-print-directory

all:
		@make -C ./libs/cubee all
		@make -C ./asm all
		@make -C ./corewar all

clean:
		@make -C ./libs/cubee clean
		@make -C ./asm clean
		@make -C ./corewar clean

fclean: clean
		@make -C ./libs/cubee fclean
		@make -C ./asm fclean
		@make -C ./corewar fclean

tests_run:
		@make -C ./libs/cubee tests_run

coverage:
		@make -C ./libs/cubee coverage

re:     fclean all

.PHONY: all clean fclean re tests_run coverage
