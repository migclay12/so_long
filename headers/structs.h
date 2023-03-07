/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:04:01 by miggonza          #+#    #+#             */
/*   Updated: 2023/03/07 12:57:30 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

//STRUCTURES
typedef struct s_comp
{
	int	e;
	int	p;
	int	c;
}	t_comp;

typedef struct s_count {
	int		x;
	int		y;
}	t_count;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_map
{
	char		**matrix;
	int			x;
	int			y;
	t_comp		comp;
}	t_map;

typedef struct s_window {
	void		*reference;
	int			x;
	int			y;
}	t_window;

	//int		win_w;
	//int		win_h;
typedef struct s_vars {
	void	*mlx;
	void	*mlx_win;
	int		img_x;
	int		img_y;
}	t_vars;

typedef struct s_wall
{
	void	*wall0;
	void	*wall1;
	void	*wall2;
	void	*wall3;
} t_wall;

typedef struct s_sprite {
	void	*floor;
	//void	*wall;
	void	*coll;
	void	*exit;
	void	*player;
	void	*enemy;
	void	*open_exit;
	t_wall	wall;
}	t_sprite;

/*
typedef struct s_image {
	void		*reference;
	t_window	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;
*/

//DO I USE IMAGE?
typedef struct s_program {
	t_window	window;
	//t_image		image;
	t_player	player;
	t_map		map;
	t_vars		vars;
	t_sprite	sprite;
	t_count		count;
	int			moves;
}	t_program;

#endif