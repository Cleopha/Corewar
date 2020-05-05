##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Gael Baron's Makefile
##

all:
		@make -C ./libs/cubee all
		@make -C ./asm all

clean:
		@make -C ./libs/cubee clean
		@make -C ./asm clean

fclean: clean
		@make -C ./libs/cubee fclean
		@make -C ./asm fclean

re:     fclean all

.PHONY: all clean fclean re
