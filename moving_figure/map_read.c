/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:48:18 by miggonza          #+#    #+#             */
/*   Updated: 2023/02/20 17:36:07 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ME GUARDA UN CARACTER DE MAS EN LA X
#include "../headers/so_long.h"

void	ft_print_error(char *str)
{
	ft_putstr("Error\n");
	ft_putstr(str);
	ft_putstr("\n");
	exit(0);
}

void	ft_map_size(int fd, t_map *size)
{
	char	*map;

	size->y = 0;
	map = get_next_line(fd);
	size->x = ft_strlen(map);
	while (map != NULL)
	{
		free(map);
		size->y++;
		map = get_next_line(fd);
		if (map && size->x != (int)ft_strlen(map))
			ft_print_error("lines are not the same length");
	}
}

char	**ft_read_map(int fd, t_map *map)
{
	int	lines;

	map->matrix = (char **)malloc(sizeof(char *) * map->x + 1);
	lines = 0;
	while (lines < map->x)
	{
		map->matrix[lines] = get_next_line(fd);
		lines++;
	}
	return (map->matrix);
}

int	ft_map_name(char *map)
{
	int	len;

	len = ft_strlen(map);
	if (map[len - 1] == 'r' && map[len - 2] == 'e'
		&& map[len - 3] == 'b' && map[len - 4] == '.')
		return (1);
	return (0);
}
