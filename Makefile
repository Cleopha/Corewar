##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Gael Baron's Makefile
##

MAKEFLAGS	+=	--no-print-directory

LFLAGS	= -L./libs -lcubee

CFLAGS	+=	-Wall -Wextra

CPPFLAGS =	-I./include -I./libs/cubee/include

TFLAGS	=	-lcriterion --coverage

NAME	=	corewar

SRC		=	src/compiler/free/instruction.c		\
			src/compiler/parser/word_parser.c	\
			src/compiler/operations.c			\
			src/compiler/util/hash.c			\
			src/compiler/writer.c

MAIN 	=	src/compiler/main.c

MOBJ	=	$(MAIN:.c=.o)

OBJ	=	$(SRC:.c=.o)

ifdef DEBUG
  CFLAGS += -ggdb3 -DDEBUG
endif

%.o:	%.c
	@echo -e -n "\033[92m[ OK ]\033[0m"
	@echo "" $<
	@gcc $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

all:	$(NAME)

$(NAME):	$(OBJ)	$(MOBJ)
		@make -C ./libs/cubee all
		@gcc $(OBJ) $(MOBJ) -o $(NAME) $(LFLAGS)

clean:
	@make -C ./libs/cubee clean
	@echo -e -n "\033[91m[ RM ]\033[0m"
	@echo "*.o"
	@rm -f $(OBJ) $(MOBJ)

fclean: clean
	@make -C ./libs/cubee fclean
	@echo -e -n "\033[91m[ RM ]\033[0m"
	@echo " Binary"
	@rm -f $(NAME)

re:     fclean all

.PHONY: all clean fclean re
