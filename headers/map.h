#ifndef MAP_H
# define MAP_H

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
void	ft_print_error(char *str);
void ft_map_size(int fd, t_map *size);
char **ft_read_map(int fd, t_map *map);
int ft_map_name(char *map);
int ft_wall_check(t_map *map);
//int ft_wall_check(t_things *things);
int ft_mid_wall_check(t_map *map);

#endif