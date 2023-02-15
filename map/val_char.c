/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:12:30 by miggonza          #+#    #+#             */
/*   Updated: 2023/02/15 18:45:13 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	ft_val_collect(t_map *map, t_player *player)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map->matrix[y])
	{
		while (map->matrix[y][x] != '\n')
		{
			if (map->matrix[y][x] == COLLECTIBLE)
				map->collectible.c++;
			if (map->matrix[y][x] == EXIT)
				map->collectible.e++;
			if (map->matrix[y][x] == START)
			{
				map->collectible.p++;
				player->xp = x;
				player->yp = y;
			}
			x++;
		}
		y++;
		x = 0;
	}
	if (map->collectible.e != 1 || map->collectible.p != 1)
		ft_print_error("Player and/or exit are not correct");
	if (map->collectible.c < 1)
		ft_print_error("Not enough collectibles");
}