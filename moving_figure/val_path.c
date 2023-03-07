/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:28:17 by miggonza          #+#    #+#             */
/*   Updated: 2023/03/07 12:29:25 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	ft_loop_check(t_map *map, int y, int x)
{
	map->matrix[y][x] = PLAYER;
	if (map->matrix[y - 1][x] != WALL && map->matrix[y - 1][x] != ENEMY
		&& map->matrix[y - 1][x] != PLAYER)
		ft_loop_check(map, y - 1, x);
	if (map->matrix[y + 1][x] != WALL && map->matrix[y + 1][x] != ENEMY
		&& map->matrix[y + 1][x] != PLAYER)
		ft_loop_check(map, y + 1, x);
	if (map->matrix[y][x - 1] != WALL && map->matrix[y][x - 1] != ENEMY
		&& map->matrix[y][x - 1] != PLAYER)
		ft_loop_check(map, y, x - 1);
	if (map->matrix[y][x + 1] != WALL && map->matrix[y][x + 1] != ENEMY
		&& map->matrix[y][x + 1] != PLAYER)
		ft_loop_check(map, y, x + 1);
}

void	ft_get_player(t_map *map, int *y, int *x)
{
	*y = 0;
	while (map->matrix[*y])
	{
		*x = 0;
		while (map->matrix[*y][*x] != '\n')
		{
			if (map->matrix[*y][*x] == PLAYER)
				return ;
			(*x)++;
		}
		(*y)++;
	}
}

void	ft_val_path(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->y)
	{
		while (map->matrix[y][x] != '\n')
		{
			if (map->matrix[y][x] == COLLECTIBLE)
				map->comp.c++;
			if (map->matrix[y][x] == EXIT)
				map->comp.e++;
			x++;
		}
		y++;
		x = 0;
	}
	ft_path_error(map);
}

void	ft_validate(t_map *map)
{
	int	x;
	int	y;

	ft_get_player(map, &y, &x);
	ft_loop_check(map, y, x);
	ft_val_path(map);
}
