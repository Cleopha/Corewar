##git reset --hard HEAD~2
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Coline SEGURET's Makefile made the 05/07/2020
##

MAKEFLAGS	+=	--no-print-directory

LFLAGS	=	-L../libs -lcubee

CFLAGS	+=	-Wall -Wextra

CPPFLAGS =	-I../include -I../libs/cubee/include

TFLAGS	=	-lcriterion --coverage

NAME	=	asm

COMPILER	:=	./src
PARSER	:=	./src/parser

SRC	=	$(COMPILER)/free/compiler.c		\
		$(COMPILER)/operations.c		\
		$(COMPILER)/compiler.c			\
		$(COMPILER)/util/hash.c			\
		$(COMPILER)/util/error.c		\

SRC	+=	$(PARSER)/word_parser.c	\
		$(PARSER)/header_parser.c \
		$(PARSER)/value_writer.c \
		$(PARSER)/instruction_manager.c	\
		$(PARSER)/compile_instruction.c	\
		$(PARSER)/compile_instruction_param.c	\
		$(PARSER)/param_checker.c	\
		$(PARSER)/flag_manager.c \
		$(PARSER)/flag_queue_manager.c \

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
	    @make -s -C ../libs/cubee all
		@gcc $(OBJ) $(MOBJ) -o $(NAME) $(LFLAGS)

clean:
	@echo -e -n "\033[91m[ RM ]\033[0m"
	@echo "*.o"
	@rm -f $(OBJ) $(MOBJ)

fclean: clean
	@echo -e -n "\033[91m[ RM ]\033[0m"
	@echo " Binary"
	@rm -f $(NAME)

re:     fclean all

.PHONY: all clean fclean re
