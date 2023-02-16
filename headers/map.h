#ifndef MAP_H
# define MAP_H

#include "move.h"

void	ft_print_error(char *str);
void	ft_map_size(int fd, t_map *size);
char	**ft_read_map(int fd, t_map *map);
int		ft_map_name(char *map);
int		ft_wall_check(t_map *map);
//int ft_wall_check(t_things *things);
int		ft_mid_wall_check(t_map *map);

void	ft_val_path(t_map *map);
void	ft_loop_check(t_map *map, int y, int x);
void	ft_get_player(t_map *map, int *y, int *x);

void	ft_val_collect(t_map *map, t_player *player);

//int	ft_putchar(int c);
//int	ft_putstr(char	*s);

void	ft_validate(t_map *map);
void ft_full_wall_check(t_map *map);

void ft_all_map(t_program *m_store, t_map *map);
#endif