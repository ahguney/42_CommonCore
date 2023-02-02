NAME = phonebook
FLAGS = -Wall -Wextra -Werror
CC = g++
RM = rm -rf
SRC = contact.class.cpp phonebook.class.cpp phonebook.cpp
OBJ = ${SRC:.cpp=.o}

all : $(NAME)

$(NAME) : $(OBJ)
		@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	
clean : 
		@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re :  clean all

.PHONY: all clean fclean re