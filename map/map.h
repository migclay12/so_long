#ifndef MAP_H
# define MAP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../moving_figure/define.h"

typedef struct s_map
{
    char **matrix;
    int x;
    int y;
} t_map;

typedef struct s_things {
	t_map		map;
}	t_things;

int	ft_putstr(char	*s);
int	ft_putchar(int c);

#endif