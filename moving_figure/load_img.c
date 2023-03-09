/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:44:15 by miggonza          #+#    #+#             */
/*   Updated: 2023/03/09 20:45:24 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	ft_save_wall(t_vars *vars, t_sprite *sprite)
{
	sprite->wall.wall0 = mlx_xpm_file_to_image(vars->mlx,
			WALL0_XPM, &vars->img_x, &vars->img_y);
	sprite->wall.wall1 = mlx_xpm_file_to_image(vars->mlx,
			WALL1_XPM, &vars->img_x, &vars->img_y);
	sprite->wall.wall2 = mlx_xpm_file_to_image(vars->mlx,
			WALL2_XPM, &vars->img_x, &vars->img_y);
	sprite->wall.wall3 = mlx_xpm_file_to_image(vars->mlx,
			WALL3_XPM, &vars->img_x, &vars->img_y);
}

void	ft_save_player(t_vars *vars, t_sprite *sprite)
{
	void	**xpm;

	xpm = &sprite->player.player;
	sprite->player.player = mlx_xpm_file_to_image(vars->mlx,
			PLAYER0_XPM, &vars->img_x, &vars->img_y);
	sprite->player.idle[0] = mlx_xpm_file_to_image(vars->mlx,
			PLAYER0_XPM, &vars->img_x, &vars->img_y);
	sprite->player.idle[1] = mlx_xpm_file_to_image(vars->mlx,
			PLAYER1_XPM, &vars->img_x, &vars->img_y);
	sprite->player.idle[2] = mlx_xpm_file_to_image(vars->mlx,
			PLAYER2_XPM, &vars->img_x, &vars->img_y);
	sprite->player.idle[3] = mlx_xpm_file_to_image(vars->mlx,
			PLAYER3_XPM, &vars->img_x, &vars->img_y);
	sprite->player.idlel0 = mlx_xpm_file_to_image(vars->mlx,
			PLAYERL0_XPM, &vars->img_x, &vars->img_y);
}

void	ft_save_exit(t_vars *vars, t_sprite *sprite)
{
	int		i;
	char	*c;
	char	*exit;
	char	*exit2;

	i = 0;
	while (i < 20)
	{
		c = ft_itoa(i);
		exit = ft_strjoin("../sprites/exit/exit", c);
		exit2 = ft_strjoin(exit, ".xpm");
		sprite->exit[i] = mlx_xpm_file_to_image(vars->mlx,
				exit2, &vars->img_x, &vars->img_y);
		i++;
		free(exit);
		free(exit2);
		free(c);
	}
}

void	ft_get_images(t_sprite *sprite, t_vars *vars)
{
	sprite->floor = mlx_xpm_file_to_image(vars->mlx,
			TILE_XPM, &vars->img_x, &vars->img_y);
	sprite->coll = mlx_xpm_file_to_image(vars->mlx,
			COLLECTIBLE_XPM, &vars->img_x, &vars->img_y);
	sprite->m_exit = mlx_xpm_file_to_image(vars->mlx,
			EXIT_XPM, &vars->img_x, &vars->img_y);
	// sprite->player.idle0 = mlx_xpm_file_to_image(vars->mlx,
	// 		PLAYER0_XPM, &vars->img_x, &vars->img_y);
	sprite->enemy = mlx_xpm_file_to_image(vars->mlx,
			ENEMY_XPM, &vars->img_x, &vars->img_y);
	sprite->open_exit = mlx_xpm_file_to_image(vars->mlx,
			OPEN_XPM, &vars->img_x, &vars->img_y);
	ft_save_exit(vars, sprite);
	ft_save_player(vars, sprite);
	ft_save_wall(vars, sprite);
	ft_sprite_error(sprite);
}

void	ft_put_wall(t_sprite *sprite, t_vars *vars, t_count *n)
{
	static int	num;

	if ((n->x == 0 && n->y == 0) || num > 3)
		num = 0;
	if (num == 0)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			sprite->wall.wall0, n->x * IMG_SZ, n->y * IMG_SZ);
	if (num == 1)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			sprite->wall.wall1, n->x * IMG_SZ, n->y * IMG_SZ);
	if (num == 2)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			sprite->wall.wall2, n->x * IMG_SZ, n->y * IMG_SZ);
	if (num == 3)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			sprite->wall.wall3, n->x * IMG_SZ, n->y * IMG_SZ);
	num++;
}

void	ft_put_images(t_sprite *sprite, t_vars *vars, t_map *map, t_count *n)
{
	mlx_put_image_to_window(vars->mlx, vars->mlx_win,
		sprite->floor, n->x * IMG_SZ, n->y * IMG_SZ);
	if (map->matrix[n->y][n->x] == WALL)
		ft_put_wall(sprite, vars, n);
	if (map->matrix[n->y][n->x] == COLLECTIBLE)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			sprite->coll, n->x * IMG_SZ, n->y * IMG_SZ);
	if (map->matrix[n->y][n->x] == EXIT_CHAR)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			sprite->m_exit, n->x * IMG_SZ, n->y * IMG_SZ);
	if (map->matrix[n->y][n->x] == PLAYER)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			sprite->player.player, n->x * IMG_SZ, n->y * IMG_SZ);
	if (map->matrix[n->y][n->x] == ENEMY)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			sprite->enemy, n->x * IMG_SZ, n->y * IMG_SZ);
}

void	ft_image_loop(t_sprite *sprite, t_vars *vars, t_map *map)
{
	t_count	n;

	ft_memset(&n, 0, sizeof(t_count));
	while (n.y < map->y)
	{
		while (map->matrix[n.y][n.x] != '\n')
		{
			ft_put_images(sprite, vars, map, &n);
			n.x++;
		}
		n.y++;
		n.x = 0;
	}
}

/*
t_window	ft_new_window(void *mlx, int widht, int height, char *name)
{
	t_window	window;

	// This mlx function creates a returns a pointer
	//to a new window with a given size and name 
	window.reference = mlx_new_window(mlx, widht, height, name);
	window.x = widht;
	window.y = height;

	// Now we 'hook' the function ft_close() to the closing window event
	//mlx_key_hook(window.reference, close, &window);
	mlx_hook(window.reference, 17, 0, ft_close, 0);

	return (window);
}
*/