#ifndef MAP_H
# define MAP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_map
{
    int x;
    int y;
} t_map;

int	ft_putstr(char	*s);
int	ft_putchar(int c);

#endif