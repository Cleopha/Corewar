##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Coline SEGURET's Makefile made the 05/07/2020
##

MAKEFLAGS	+=	--no-print-directory

RM			?=	rm -f
ECHO		=	`which echo`

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
		$(COMPILER)/util/my_atoi.c		\
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
	@$(ECHO) -e -n "\033[92m[ OK ]\033[0m"
	@$(ECHO) "" $<
	@gcc $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

all:	$(NAME)

$(NAME):	$(OBJ)	$(MOBJ)
	    @make -s -C ../libs/cubee all
		@gcc $(OBJ) $(MOBJ) -o $(NAME) $(LFLAGS)

clean:
	@for f in $(TOBJ); do if [ -f $$f ]; then $(ECHO) -e "\033[35m[ TU ]\033[0m" $$f; fi; done;
	@for f in $(OBJ); do if [ -f $$f ]; then $(ECHO) -e "\033[91m[ RM ]\033[0m" $$f; fi; done;
	@for f in $(MOBJ); do if [ -f $$f ]; then $(ECHO) -e "\033[91m[ RM ]\033[0m" $$f; fi; done;
	@$(RM) $(OBJ) $(MOBJ) $(TOBJ)
	@$(RM) $(GCDA)
	@$(RM) $(GCNO)

fclean: clean
	@if [ -f $(NAME) ]; then $(ECHO) -e "\033[33m[ RM ]\033[0m" $(NAME); fi;
	@$(RM) $(NAME) unit_test

re:     fclean all

.PHONY: all clean fclean re
