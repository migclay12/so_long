#ifndef MAP_H
# define MAP_H

typedef struct s_collect
{
	int e;
	int p;
	int c;
} t_collect;

typedef struct s_player
{
	int xp;
	int yp;
} t_player;

typedef struct s_map
{
	char **matrix;
	int x;
	int y;
	t_collect collectible;
	t_player player;
} t_map;

typedef struct s_things {
	t_map		map;
}	t_things;

void	ft_print_error(char *str);
void	ft_map_size(int fd, t_map *size);
char	**ft_read_map(int fd, t_map *map);
int		ft_map_name(char *map);
int		ft_wall_check(t_map *map);
//int ft_wall_check(t_things *things);
int		ft_mid_wall_check(t_map *map);
void	ft_val_collect(t_map *map);

//int	ft_putchar(int c);
//int	ft_putstr(char	*s);

#endif