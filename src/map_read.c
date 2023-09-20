/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:48:18 by miggonza          #+#    #+#             */
/*   Updated: 2023/09/20 10:44:02 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ME GUARDA UN CARACTER DE MAS EN LA X
#include "../headers/so_long.h"

static char	**ft_free_map(char **matrix, int i)
{
	while (i >= 0)
	{
		free(matrix[i]);
		i--;
	}
	free(matrix);
	return (0);
}

void	ft_map_size(int fd, t_map *size)
{
	char	*line;

	size->y = 0;
	line = get_next_line(fd);
	size->x = ft_strlen(line);
	while (line != NULL)
	{
		free(line);
		size->y++;
		line = get_next_line(fd);
		if (line && size->x != (int)ft_strlen(line))
			ft_print_error("lines are not the same length");
	}
}

char	**ft_read_map(int fd, t_map *map)
{
	int	col;

	map->matrix = (char **)malloc(sizeof(char *) * map->y + 1);
	if (!map->matrix)
		return (0);
	col = 0;
	while (col < map->y)
	{
		map->matrix[col] = get_next_line(fd);
		if (!map->matrix[col])
			return (ft_free_map(map->matrix, col));
		col++;
	}
	if (map->x > 41)
		ft_print_error("Map is too wide for screen");
	if (map->y > 22)
		ft_print_error("Map is too tall for screen");
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
