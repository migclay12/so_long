/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:58:17 by miggonza          #+#    #+#             */
/*   Updated: 2023/02/21 19:23:57 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include	"so_long.h"
//#include "map.h"
# include	"define.h"
# include	"structs.h"
# include	"headers.h"
# include	"../libft/libft.h"

int ft_close();

//MAP
void		ft_print_error(char *str);
void		ft_map_size(int fd, t_map *size);
char		**ft_read_map(int fd, t_map *map);
int			ft_map_name(char *map);
int			ft_wall_check(t_map *map);
//int ft_wall_check(t_things *things);
int			ft_mid_wall_check(t_map *map);

void		ft_val_path(t_map *map);
void		ft_loop_check(t_map *map, int y, int x);
void		ft_get_player(t_map *map, int *y, int *x);

void		ft_val_collect(t_map *map, t_player *player);
void		ft_errors(t_program *p);

//int	ft_putchar(int c);
//int	ft_putstr(char	*s);

void		ft_validate(t_map *map);
void		ft_full_wall_check(t_map *map);

void		ft_all_map(t_program *m_store, t_map *map);

//MOVE

//t_image		ft_new_sprite(void *mlx, char *path);
int			ft_input(int key, t_program *program);
//int ft_update (void *param);
t_window	ft_new_window(void *mlx, int widht, int height, char *name);
//int	close(int keycode, t_program *vars);
void		ft_get_images(t_sprite *sprite, t_vars *vars);

void		ft_put_images(t_sprite *sprite, t_vars *vars, t_map *map, t_count *n);
void        ft_image_loop(t_sprite *sprite, t_vars *vars, t_map *map);
void		ft_move(t_program *p, int x, int y);

int			ft_update (void *param);
#endif