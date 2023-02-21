/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:35:19 by miggonza          #+#    #+#             */
/*   Updated: 2023/02/20 17:36:20 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

//se puede hacer void?
int	ft_wall_check(t_map *map)
{
	int	i;
	int	j;
	int	top;
	int	bot;

	i = 0;
	while (map->matrix[0][i] != '\n')
	{
		top = 1;
		if (map->matrix[0][i] != WALL)
			return (0);
		i++;
	}
	j = 0;
	while (map->matrix[map->y - 1][j] != '\n')
	{
		bot = 1;
		if (map->matrix[map->y - 1][j] != WALL)
			return (0);
		j++;
	}
	if (top == 1 && bot == 1)
		return (1);
	return (0);
}

int	ft_mid_wall_check(t_map *map)
{
	int	i;

	i = 1;
	while (i < map->y - 1)
	{
		if (map->matrix[i][0] != WALL || map->matrix[i][map->x - 2] != WALL)
			return (0);
		i++;
	}
	return (1);
}

void	ft_full_wall_check(t_map *map)
{
	int	wall;

	wall = ft_wall_check(map);
	if (wall != 1)
		ft_print_error("map is not surrounded by walls");
	wall = ft_mid_wall_check(map);
	if (wall != 1)
		ft_print_error("map is not surrounded by walls");
}
