NAME = push_swap

SRC = $(wildcard ./*.c libft/*.c)

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAG =  -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC)  $(CFLAG)  $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
