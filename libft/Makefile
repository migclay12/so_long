NAME=libft.a
CC=cc
CFLAGS=-Wall -Wextra -Werror
OPTIONS= -c -I.
AR= ar rc
FUNCTIONS=	ft_atoi.c ft_bzero.c \
			ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
			ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
			ft_strrchr.c ft_toupper.c ft_tolower.c ft_strnstr.c \
			ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
			ft_strdup.c ft_calloc.c ft_substr.c ft_strjoin.c \
			ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_strmapi.c \
			ft_strtrim.c ft_putnbr_fd.c ft_striteri.c ft_split.c \
			get_next_line.c	get_next_line_utils.c \
			ft_putstr.c 
#ft_itoa.c
#BONUS= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstiter.c ft_lstclear.c ft_lstmap.c

OBJECTS = ${FUNCTIONS:.c=.o}

#BONUS_OBJECTS = ${BONUS:.c=.o}

all: ${NAME}

${NAME}: ${OBJECTS}
		${AR} ${NAME} ${OBJECTS}

clean:
		rm -f ${OBJECTS} 
#${BONUS_OBJECTS}

fclean: clean
		rm -f ${NAME}

re: fclean all

#bonus: ${BONUS_OBJECTS}
#		${AR} ${NAME} ${BONUS_OBJECTS}

.PHONY: clean fclean all re 
#bonus
