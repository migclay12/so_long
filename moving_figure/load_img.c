/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:44:15 by miggonza          #+#    #+#             */
/*   Updated: 2023/03/10 15:44:28 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

/*
void	ft_save_wall(t_vars *vars, t_sprite *sprite)
{
	sprite->wall[0] = mlx_xpm_file_to_image(vars->mlx,
			WALL0_XPM, &vars->img_x, &vars->img_y);
	sprite->wall[1] = mlx_xpm_file_to_image(vars->mlx,
			WALL1_XPM, &vars->img_x, &vars->img_y);
	sprite->wall[2] = mlx_xpm_file_to_image(vars->mlx,
			WALL2_XPM, &vars->img_x, &vars->img_y);
	sprite->wall[3] = mlx_xpm_file_to_image(vars->mlx,
			WALL3_XPM, &vars->img_x, &vars->img_y);
}
*/
/*
void	ft_save_player(t_vars *vars, t_sprite *sprite)
{
	sprite->player = mlx_xpm_file_to_image(vars->mlx,
			PLAYER0_XPM, &vars->img_x, &vars->img_y);
	sprite->idle[0] = mlx_xpm_file_to_image(vars->mlx,
			PLAYER0_XPM, &vars->img_x, &vars->img_y);
	sprite->idle[1] = mlx_xpm_file_to_image(vars->mlx,
			PLAYER1_XPM, &vars->img_x, &vars->img_y);
	sprite->idle[2] = mlx_xpm_file_to_image(vars->mlx,
			PLAYER2_XPM, &vars->img_x, &vars->img_y);
	sprite->idle[3] = mlx_xpm_file_to_image(vars->mlx,
			PLAYER3_XPM, &vars->img_x, &vars->img_y);
	sprite->idlel0 = mlx_xpm_file_to_image(vars->mlx,
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
*/

void	ft_save_sprites(t_vars *vars, t_sprite *sprite, char *address, char map)
{
	int		i;
	char	*c;
	char	*add0;
	char	*add1;

	i = 0;
	while (i < 20)
	{
		c = ft_itoa(i);
		add0 = ft_strjoin(address, c);
		add1 = ft_strjoin(add0, ".xpm");
		if (map == 'E')
			sprite->sprites[EXIT_SPRITE][i] = mlx_xpm_file_to_image(vars->mlx,
					add1, &vars->img_x, &vars->img_y);
		if (map == 'P' && i < 4)
			sprite->idle[i] = mlx_xpm_file_to_image(vars->mlx,
					add1, &vars->img_x, &vars->img_y);
		if (map == '1' && i < 4)
			sprite->wall[i] = mlx_xpm_file_to_image(vars->mlx,
					add1, &vars->img_x, &vars->img_y);
		if (map == 'D' && i < 6)
			sprite->dead[i] = mlx_xpm_file_to_image(vars->mlx,
					add1, &vars->img_x, &vars->img_y);
		i++;
		free(add0);
		free(add1);
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
	sprite->idlel0 = mlx_xpm_file_to_image(vars->mlx,
			PLAYERL0_XPM, &vars->img_x, &vars->img_y);
	sprite->player = mlx_xpm_file_to_image(vars->mlx,
			PLAYER0_XPM, &vars->img_x, &vars->img_y);
	sprite->enemy = mlx_xpm_file_to_image(vars->mlx,
			ENEMY_XPM, &vars->img_x, &vars->img_y);
	ft_save_sprites(vars, sprite, "../sprites/exit/exit", EXIT_CHAR);
	ft_save_sprites(vars, sprite, "../sprites/player/pidle", PLAYER);
	ft_save_sprites(vars, sprite, "../sprites/wall", WALL);
	ft_save_sprites(vars, sprite, "../sprites/player/dead", DEAD);
	//ft_save_wall(vars, sprite);
	ft_sprite_error(sprite);
}

void	ft_put_images(t_sprite *sprite, t_vars *vars, t_map *map, t_count *n)
{
	static int	num;

	if ((n->x == 0 && n->y == 0) || num > 3)
		num = 0;
	mlx_put_image_to_window(vars->mlx, vars->mlx_win,
		sprite->floor, n->x * IMG_SZ, n->y * IMG_SZ);
	if (map->matrix[n->y][n->x] == WALL)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			sprite->wall[num], n->x * IMG_SZ, n->y * IMG_SZ);
	if (map->matrix[n->y][n->x] == COLLECTIBLE)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			sprite->coll, n->x * IMG_SZ, n->y * IMG_SZ);
	if (map->matrix[n->y][n->x] == EXIT_CHAR)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			sprite->m_exit, n->x * IMG_SZ, n->y * IMG_SZ);
	if (map->matrix[n->y][n->x] == PLAYER)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			sprite->player, n->x * IMG_SZ, n->y * IMG_SZ);
	if (map->matrix[n->y][n->x] == ENEMY)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			sprite->enemy, n->x * IMG_SZ, n->y * IMG_SZ);
	num++;
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
