NAME = bsq
SRC = ./srcs/
CFILE = $(SRC)functions.c $(SRC)morefunctions.c $(SRC)andmore.c
INC = ./includes/header.h
MAINFILE = ./main.c

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(CFILE) -I $(INC)
	gcc -Wall -Wextra -Werror *.o $(MAINFILE) -o $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
