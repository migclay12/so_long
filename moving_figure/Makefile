NAME = sample.out
SRC = image.c main.c hooks.c map_read.c val_char.c val_path.c window.c
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
