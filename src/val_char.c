/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:12:30 by miggonza          #+#    #+#             */
/*   Updated: 2025/09/24 00:11:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	get_player(t_map *map, t_player *player, int y, int x)
{
	map->comp.p++;
	player->x = x;
	player->y = y;
}

void	ft_val_collect(t_map *map, t_player *player)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (map->matrix[y][x] != '\n')
		{
			if (!ft_strchr(VAL_CHAR, map->matrix[y][x]))
				ft_print_error("Invalid char in map");
			if (map->matrix[y][x] == COLLECTIBLE)
				map->comp.c++;
			if (map->matrix[y][x] == EXIT)
			{
				map->comp.e++;
				map->comp.exit_x = x;
				map->comp.exit_y = y;
			}	
			if (map->matrix[y][x] == PLAYER)
				get_player(map, player, y, x);
			x++;
		}
		y++;
	}
}
