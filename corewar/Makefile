##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Coline SEGURET's Makefile made the 05/07/2020
##

CC			?=	gcc

MAKEFLAGS	+=	--no-print-directory

RM			?=	rm -f
ECHO		=	`which echo`

LFLAGS		=	-L../libs -lcubee

CFLAGS		+=	-Wall -Wextra

CPPFLAGS 	=	-I../include -I../libs/cubee/include

TFLAGS		=	-lcriterion --coverage

NAME		=	corewar

MEMORY		:=	./src/memory_init
INSTRUCTION	:=	./src/instruction

SRC			=	src/endian_conversion.c	\
				src/error_display.c		\
				src/error_management.c	\
				src/init_champ.c		\
				src/my_put_hexa.c		\
				src/my_utils.c			\
				src/retrieve_int.c		\
				src/execution_loop.c	\
				src/put_nb_in_str.c		\
				src/remove_champ.c		\
				src/my_memset.c

SRC			+=	$(INSTRUCTION)/add.c		\
				$(INSTRUCTION)/aff.c		\
				$(INSTRUCTION)/and.c		\
				$(INSTRUCTION)/fork.c		\
				$(INSTRUCTION)/get_params.c	\
				$(INSTRUCTION)/ld.c			\
				$(INSTRUCTION)/ldi.c		\
				$(INSTRUCTION)/lfork.c		\
				$(INSTRUCTION)/live.c		\
				$(INSTRUCTION)/lld.c		\
				$(INSTRUCTION)/lldi.c		\
				$(INSTRUCTION)/or.c			\
				$(INSTRUCTION)/set_begin_instruction.c	\
				$(INSTRUCTION)/st.c			\
				$(INSTRUCTION)/sti.c		\
				$(INSTRUCTION)/sub.c		\
				$(INSTRUCTION)/xor.c		\
				$(INSTRUCTION)/zjmp.c

SRC			+=	$(MEMORY)/address_checking.c	\
				$(MEMORY)/header_handling.c		\
				$(MEMORY)/init_param.c			\
				$(MEMORY)/mem_init.c			\
				$(MEMORY)/print_mem.c			\
				$(MEMORY)/set_params.c

MAIN 		=	src/main.c

MOBJ		=	$(MAIN:.c=.o)

OBJ			=	$(SRC:.c=.o)

ifdef DEBUG
	CFLAGS += -ggdb3 -DDEBUG
endif

%.o:	%.c
	@$(CC) -no-pie $(CFLAGS) $(CPPFLAGS) -c -o $@ $< && \
	($(ECHO) -e "\033[92m[ OK ]\033[0m" $<) || \
	($(ECHO) -e "\033[91m[ NO COMPIL ]\033[0m" $<; false)

all:	$(NAME)

$(NAME):	$(OBJ)	$(MOBJ)
	@make -s -C ../libs/cubee all
	@$(CC) -no-pie $(OBJ) $(MOBJ) -o $(NAME) $(LFLAGS)

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
