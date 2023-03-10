NAME = so_long
SRC = main.c hooks.c map_read.c val_char.c error.c\
		val_path.c load_img.c wall_check.c map_check.c update.c
OBJ = $(SRC:.c=.o)
#-fsanitize=address
FLAGS = -Wall -Wextra -Werror -fsanitize=address
LINKS = -lmlx -framework OpenGL -framework AppKit

LIB = ../libft

all: ${NAME}

${NAME}: ${OBJ}
		make -C $(LIB)
		@gcc $(FLAGS) $(OBJ) $(LINKS) -o $(NAME) $(LIB)/libft.a

$(OBJ): $(SRC)
		@gcc $(FLAGS) -c $(SRC)

exe: all
		@./$(NAME)

clean:
		@rm -rf $(OBJ)
		@make -C $(LIB) clean

fclean: clean
		@rm -rf $(NAME)
		@make -C $(LIB) fclean

re: fclean all

.PHONY: clean fclean all re
