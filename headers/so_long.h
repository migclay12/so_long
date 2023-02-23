/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:58:17 by miggonza          #+#    #+#             */
/*   Updated: 2023/02/23 14:29:54 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include	"so_long.h"
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
int			ft_mid_wall_check(t_map *map);
void		ft_val_path(t_map *map);
void		ft_path_error(t_map *map);
void		ft_loop_check(t_map *map, int y, int x);
void		ft_get_player(t_map *map, int *y, int *x);
void		ft_val_collect(t_map *map, t_player *player);
void		ft_char_error(t_program *p);
void		ft_validate(t_map *map);
void		ft_wall_error(t_map *map);
void		ft_all_map(t_program *m_store, t_map *map, char *name);

//MOVE
int			ft_input(int key, t_program *program);
void        ft_sprite_error(t_sprite *sprite);
void		ft_get_images(t_sprite *sprite, t_vars *vars);
void		ft_put_images(t_sprite *sprite, t_vars *vars, t_map *map, t_count *n);
void        ft_image_loop(t_sprite *sprite, t_vars *vars, t_map *map);
void		ft_move(t_program *p, int x, int y);
void		ft_text_screen(t_program *p);

//int			ft_update (void *param);

#endif