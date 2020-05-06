##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Gael Baron's Makefile
##

MAKEFLAGS	+=	--no-print-directory

LFLAGS	=	-L../libs -lcubee

CFLAGS	+=	-Wall -Wextra

CPPFLAGS =	-I../include -I../libs/cubee/include

TFLAGS	=	-lcriterion --coverage

NAME	=	asm

COMPILER	:=	./src/
PARSER	:=	./src/parser

SRC	=	$(COMPILER)/free/instruction.c		\
		$(COMPILER)/operations.c			\
		$(COMPILER)/util/hash.c			\
		$(COMPILER)/writer.c	\

SRC	+=	$(PARSER)/word_parser.c	\
		$(PARSER)/check_param.c	\
		$(PARSER)/convert_in_bin.c	\
		$(PARSER)/error_management.c	\

MAIN 	=	src/main.c

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
		@make -C ../libs/cubee all
		@gcc $(OBJ) $(MOBJ) -o $(NAME) $(LFLAGS)

clean:
	@echo -e -n "\033[91m[ RM ]\033[0m"
	@echo "*.o"
	@rm -f $(OBJ) $(MOBJ)

fclean: clean
	@make -C ../libs/cubee fclean
	@echo -e -n "\033[91m[ RM ]\033[0m"
	@echo " Binary"
	@rm -f $(NAME)

re:     fclean all

.PHONY: all clean fclean re
