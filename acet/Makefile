NAME	= ft_containers
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
SRC		= $(shell find . -type f -name "main.cpp")
OBJ		= $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean re