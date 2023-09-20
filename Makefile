NAME = so_long

SRC = src/main.c src/hooks.c src/map_read.c src/val_char.c \
		src/error.c src/val_path.c src/load_img.c src/wall_check.c \
		src/map_check.c src/update.c

OBJ = $(SRC:.c=.o)
#-fsanitize=address
FLAGS = -Wall -Wextra -Werror

LINKS = -lmlx -framework OpenGL -framework AppKit

LIB = libft

all: ${NAME}

${NAME}: ${OBJ}
		@make -C $(LIB)
		@gcc $(FLAGS) $(OBJ) $(LINKS) -o $(NAME) $(LIB)/libft.a

#$(OBJ): $(SRC)
#		@gcc $(FLAGS) -c $(SRC)

exe: all
		@./$(NAME) maps/map0.ber

clean:
		@rm -rf $(OBJ)
		@make -C $(LIB) clean

fclean: clean
		@rm -rf $(NAME)
		@make -C $(LIB) fclean

re: fclean all

.PHONY: clean fclean all re
