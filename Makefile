##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Arthur Teisseire
##

DSRC	=	$(realpath src)/
FUNC	=	$(DSRC)/functions/
SRC     =	$(DSRC)main.c \
		$(DSRC)functions.c
INC	=	$(realpath include)
CFLAGS	=	-Wall -W -Wextra -I$(INC) -g
LDFLAGS	=	-l c_graph_prog
OBJ	=	$(SRC:.c=.o) $(SRC_UT:.c=.o)
NAME	=	a.out

all: $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f *.gcno
	rm -f *.gcna
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
	make clean
