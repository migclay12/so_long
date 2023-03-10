/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:25:56 by miggonza          #+#    #+#             */
/*   Updated: 2023/03/10 16:50:52 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	ft_print_error(char *str)
{
	ft_putstr("Error\n");
	ft_putstr(str);
	ft_putstr("\n");
	exit(0);
}

void	ft_wall_error(t_map *map)
{
	if (ft_wall_check(map) != 1)
		ft_print_error("The map is not surrounded by walls top or bot");
	if (ft_mid_wall_check(map) != 1)
		ft_print_error("One of the map sides is not surrounded by walls");
}

void	ft_char_error(t_program *p)
{
	if (p->map.comp.e < 1)
		ft_print_error("The exit is missing");
	if (p->map.comp.e > 1)
		ft_print_error("There are too many exits in the map");
	if (p->map.comp.p < 1)
		ft_print_error("The player is missing");
	if (p->map.comp.p != 1)
		ft_print_error("There are too many players in the map");
	if (p->map.comp.c < 1)
		ft_print_error("There must be at least one collectible");
}

void	ft_path_error(t_map *map)
{
	if (map->comp.e > 0)
		ft_print_error("Path is not valid, exit could not be reached");
	if (map->comp.c == 1)
		ft_print_error("Path is not valid, one collectible is missing");
	if (map->comp.c > 1)
	{
		ft_printf("%d collectibles are missing\n", map->comp.c);
		ft_print_error("Path is not valid");
	}
}

void	ft_sprite_error(t_program *p)
{

	int	i;

	i = 0;
	while (i < 20)
	{
		if (!p->sprites[WALL_SP][i] && i < 4)
			ft_print_error("Wall sprite has not loadeed propperly");
		if (!p->sprites[EXIT_SP][i])
			ft_print_error("Exit sprite has not loadeed propperly");
		if (!p->sprites[PLAYER_SP][i] && i < 4)
			ft_print_error("Player sprite has not loadeed propperly");
		if (!p->sprites[DEAD_SP][i] && i < 6)
			ft_print_error("Player sprite has not loadeed propperly");
		i++;
	}

	if (!p->sprites[FLOOR_SP][0])
		ft_print_error("Floor sprite has not loadeed properly");
	if (!p->sprites[COLL_SP][0])
		ft_print_error("Collectible sprite has not loadeed propperly");
	if (!p->sprites[EXIT_SP][20])
		ft_print_error("Main exit sprite has not loadeed propperly");
	if (!p->sprites[PLAYERL_SP][0])
		ft_print_error("Player idlel0 sprite has not loadeed propperly");
	if (!p->sprites[PLAYER_SP][0])
		ft_print_error("Player knight sprite has not loadeed propperly");
	if (!p->sprites[ENEMY_SP][0])
		ft_print_error("Enemy sprite has not loadeed propperly");
}
