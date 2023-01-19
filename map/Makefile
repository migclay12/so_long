NAME = sample.out
SRC = val_char.c
OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror
LINKS = -lmlx -framework OpenGL -framework AppKit

all: ${NAME}

${NAME}: ${OBJ}
		@gcc $(FLAGS) $(OBJ) $(LINKS) -o $(NAME)

$(OBJ): $(SRC)
		@gcc $(FLAGS) -c $(SRC)

exe: all
		@./$(NAME)

clean:
		@rm -rf $(OBJ)

fclean: clean
		@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re
