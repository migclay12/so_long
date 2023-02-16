/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:28:17 by miggonza          #+#    #+#             */
/*   Updated: 2023/02/15 18:38:43 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	ft_loop_check(t_map *map, int y, int x)
{
	map->matrix[y][x] = START;
	if (map->matrix[y - 1][x] != WALL
		&& map->matrix[y - 1][x] != START)
		ft_loop_check(map, y - 1, x);
	if (map->matrix[y + 1][x] != WALL
		&& map->matrix[y + 1][x] != START)
		ft_loop_check(map, y + 1, x);
	if (map->matrix[y][x - 1] != WALL
		&& map->matrix[y][x - 1] != START)
		ft_loop_check(map, y, x - 1);
	if (map->matrix[y][x + 1] != WALL
		&& map->matrix[y][x + 1] != START)
		ft_loop_check(map, y, x + 1);
}


void ft_get_player(t_map *map, int *y, int *x)
{
    *y = 0;
    while (map->matrix[*y])
    {
        *x = 0;
        while (map->matrix[*y][*x] != '\n')
        {
            if (map->matrix[*y][*x] == START)
				return ;
            (*x)++;
        }
        (*y)++;
    }
}

void ft_val_path(t_map *map)
{
    int x;
    int y;

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
            x++;
        }
        y++;
        x = 0;
    }
    if(map->collectible.e > 0 || map->collectible.c > 0)
        ft_print_error("Path not correct");
}

void	ft_validate(t_map *map)
{
	int	x;
	int	y;

	ft_get_player(map, &y, &x);
	ft_loop_check(map, y, x);
	ft_val_path(map);
}