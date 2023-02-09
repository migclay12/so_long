NAME = map.a
SRC = utils.c map_read.c main.c
OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror
LINKS = -lmlx -framework OpenGL -framework AppKit

LIB = ../libft/libft.a

all: ${NAME}

${NAME}: ${OBJ}
		@gcc $(FLAGS) $(OBJ) $(LINKS) $(LIB) -o $(NAME)

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
