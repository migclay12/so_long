/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:04:01 by miggonza          #+#    #+#             */
/*   Updated: 2023/09/18 12:54:17 by miggonza         ###   ########.fr       */
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
	int	exit_x;
	int	exit_y;
}	t_comp;

typedef struct s_count {
	int		x;
	int		y;
}	t_count;

typedef struct s_player
{
	int		x;
	int		y;
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

typedef struct s_vars {
	void	*mlx;
	void	*mlx_win;
	int		img_x;
	int		img_y;
}	t_vars;

typedef struct s_program {
	t_window	window;
	t_player	player;
	t_map		map;
	t_vars		vars;
	t_count		count;
	void		*sprites[8][21];
	int			time;
	int			moves;
}	t_program;

#endif