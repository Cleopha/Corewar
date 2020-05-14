##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Coline SEGURET's Makefile made the 05/07/2020
##

CC			?=	gcc

MAKEFLAGS	+=	--no-print-directory

LFLAGS	=	-L../libs -lcubee

CFLAGS	+=	-Wall -Wextra

CPPFLAGS =	-I../include -I../libs/cubee/include

TFLAGS	=	-lcriterion --coverage

NAME	=	corewar

SRC	=	src/init_champ.c		\
		src/error_management.c	\
		src/my_utils.c			\
		src/header_handling.c	\
		src/mem_init.c			\
		src/endian_conversion.c	\
		src/address_checking.c	\
		src/retrieve_int.c		\
		src/error_display.c		\
		src/my_put_hexa.c		\
		src/print_mem.c			\
		src/init_param.c		\
		src/set_params.c

MAIN 	=	src/main.c

MOBJ	=	$(MAIN:.c=.o)

OBJ	=	$(SRC:.c=.o)

ifdef DEBUG
  CFLAGS += -ggdb3 -DDEBUG
endif

%.o:	%.c
	-@$(CC) -no-pie $(CFLAGS) $(CPPFLAGS) -c -o $@ $< && \
	(echo -e "\033[92m[ OK ]\033[0m" $<) || \
	(echo -e "\033[91m[ NO COMPIL ]\033[0m" $<; exit 1)

all:	$(NAME)

$(NAME):	$(OBJ)	$(MOBJ)
	@make -s -C ../libs/cubee all
	@gcc -no-pie $(OBJ) $(MOBJ) -o $(NAME) $(LFLAGS)

clean:
	@echo -e "\033[91m[ RM ]\033[0m *.o"
	@rm -f $(OBJ) $(MOBJ)

fclean: clean
	@make -s -C ../libs/cubee fclean
	@echo -e "\033[91m[ RM ]\033[0m Binary"
	@rm -f $(NAME)

re:     fclean all

.PHONY: all clean fclean re
