/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:44:15 by miggonza          #+#    #+#             */
/*   Updated: 2023/03/10 16:50:25 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
/*
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
*/

void	ft_save_sprites(t_program *p, char *address, int img, int num)
{
	int		i;
	char	*c;
	char	*add0;
	char	*add1;

	i = 0;
	while (i < num)
	{
		c = ft_itoa(i);
		add0 = ft_strjoin(address, c);
		add1 = ft_strjoin(add0, ".xpm");
		printf("%s\n", add1);
		p->sprites[img][i] = mlx_xpm_file_to_image(p->vars.mlx,
				add1, &p->vars.img_x, &p->vars.img_y);
		i++;
		free(add0);
		free(add1);
		free(c);
	}
}

void	ft_get_images(t_program *p)
{
	// p->floor = mlx_xpm_file_to_image(vars->mlx,
	// 		TILE_XPM, &vars->img_x, &vars->img_y);
	// p->coll = mlx_xpm_file_to_image(vars->mlx,
	// 		COLLECTIBLE_XPM, &vars->img_x, &vars->img_y);
	// p->m_exit = mlx_xpm_file_to_image(vars->mlx,
	// 		EXIT_XPM, &vars->img_x, &vars->img_y);
	// p->idlel0 = mlx_xpm_file_to_image(vars->mlx,
	// 		PLAYERL0_XPM, &vars->img_x, &vars->img_y);
	// p->player = mlx_xpm_file_to_image(vars->mlx,
	// 		PLAYER0_XPM, &vars->img_x, &vars->img_y);
	// p->enemy = mlx_xpm_file_to_image(vars->mlx,
	// 		ENEMY_XPM, &vars->img_x, &vars->img_y);
	ft_save_sprites(p, "../sprites/enemy", ENEMY_SP, 1);
	ft_save_sprites(p, "../sprites/floor", FLOOR_SP, 1);
	ft_save_sprites(p, "../sprites/skull", COLL_SP, 1);
	ft_save_sprites(p, "../sprites/player/pidlel", PLAYERL_SP, 1);
	ft_save_sprites(p, "../sprites/exit/exit", EXIT_SP, 21);
	ft_save_sprites(p, "../sprites/player/pidler", PLAYER_SP, 4);
	ft_save_sprites(p, "../sprites/wall", WALL_SP, 4);
	ft_save_sprites(p, "../sprites/player/dead", DEAD_SP, 6);
	//ft_save_wall(vars, sprite);
	ft_sprite_error(p);
}

void	ft_put_images(t_program *p, t_vars *vars, t_map *map, t_count *n)
{
	static int	num;

	if ((n->x == 0 && n->y == 0) || num > 3)
		num = 0;
	mlx_put_image_to_window(vars->mlx, vars->mlx_win,
		p->sprites[FLOOR_SP][0], n->x * IMG_SZ, n->y * IMG_SZ);
	if (map->matrix[n->y][n->x] == WALL)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			p->sprites[WALL_SP][num], n->x * IMG_SZ, n->y * IMG_SZ);
	if (map->matrix[n->y][n->x] == COLLECTIBLE)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			p->sprites[COLL_SP][0], n->x * IMG_SZ, n->y * IMG_SZ);
	if (map->matrix[n->y][n->x] == EXIT)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			p->sprites[EXIT_SP][20], n->x * IMG_SZ, n->y * IMG_SZ);
	if (map->matrix[n->y][n->x] == PLAYER)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			p->sprites[PLAYER_SP][0], n->x * IMG_SZ, n->y * IMG_SZ);
	if (map->matrix[n->y][n->x] == ENEMY)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			p->sprites[ENEMY_SP][0], n->x * IMG_SZ, n->y * IMG_SZ);
	num++;
}

void	ft_image_loop(t_program *p, t_vars *vars, t_map *map)
{
	t_count	n;

	ft_memset(&n, 0, sizeof(t_count));
	while (n.y < map->y)
	{
		while (map->matrix[n.y][n.x] != '\n')
		{
			ft_put_images(p, vars, map, &n);
			n.x++;
		}
		n.y++;
		n.x = 0;
	}
}
