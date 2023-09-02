NAME = minishell
CC = gcc -g
SRC = $(wildcard ./srcs/*.c)
OBJ = $(SRC:.c=.o)
SRC1 = $(wildcard ./libft/*.c)
OBJ1 = $(SRC1:.c=.o)
CFLAGS = -Wall -Wextra -Werror
READLINE = libs/readline/libreadline.a
READHISTORY = libs/readline/libhistory.a

all: $(NAME)

$(NAME) : $(OBJ) $(OBJ1)
	@$(CC) $(CFLAGS) $(READLINE) $(READHISTORY) $(OBJ) $(OBJ1) -lreadline -lncurses -o $(NAME)

re : fclean all

clean :
	@rm -rf ./srcs/*.o
	@rm -rf ./libft/*.o

fclean : clean
	@rm -rf $(NAME)

.PHONY : all fclean clean re