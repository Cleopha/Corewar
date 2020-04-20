##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Gael Baron's Makefile
##

MAKEFLAGS	+=	--no-print-directory

LFLAGS	=

CFLAGS	=	-Wall -Wextra

CPPFLAGS =	-I./include

TFLAGS	=	-lcriterion --coverage

NAME	=	corewar

SRC	=

MAIN 	=	src/main.c

MOBJ	=	$(MAIN:.c=.o)

OBJ	=	$(SRC:.c=.o)

%.o:	%.c
	@echo -e -n "\033[92m[ OK ]\033[0m"
	@echo "" $<
	@gcc $(CFLAGS) $(CPPFLAGS) -c -o $@ $<


all:	$(NAME)

$(NAME):	$(OBJ)	$(MOBJ)
		@make -C lib
		@gcc $(OBJ) $(MOBJ) -o $(NAME) $(LFLAGS)

debug:	CFLAGS	+=	-g
debug:	$(NAME)

clean:
	@make clean -C lib
	@echo -e -n "\033[91m[ RM ]\033[0m"
	@echo " *.o"
	@rm -f $(OBJ)
	@rm -f $(MOBJ)

fclean: clean
	@make fclean -C lib
	@echo -e -n "\033[91m[ RM ]\033[0m"
	@echo " Binary"
	@rm -f $(NAME)

re:     fclean all

.PHONY: all clean fclean re
