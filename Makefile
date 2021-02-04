
CC = gcc

NAME = eval_expr

SRC = eval_expr.c tool.c tool2.c

OBJ = $(SRC:.c=.o)

FLG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	$(CC) $(FLG) -c $(SRC) 
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

re: fclean all
