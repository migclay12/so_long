/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:33:09 by miggonza          #+#    #+#             */
/*   Updated: 2025/09/24 01:00:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_open_file(char *map)
{
	int	fd;

	if (!ft_map_name(map))
		ft_print_error("The file map is not .ber");
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_print_error("Map file does not exist or cannot be opened");
	return (fd);
}

void	ft_all_map(t_program *m_store, t_map *map, char *name)
{
	int	fd;

	ft_memset(map, 0, sizeof(t_map));
	ft_memset(m_store, 0, sizeof(t_program));
	fd = ft_open_file(name);
	ft_map_size(fd, map);
	close(fd);
	fd = ft_open_file(name);
	ft_map_size(fd, &m_store->map);
	close(fd);
	fd = ft_open_file(name);
	map->matrix = ft_read_map(fd, map);
	close(fd);
	fd = ft_open_file(name);
	m_store->map.matrix = ft_read_map(fd, &m_store->map);
	close(fd);
	ft_wall_error(map);
	ft_val_collect(&m_store->map, &m_store->player);
	ft_char_error(m_store);
	ft_validate(map);
	m_store->window.y = m_store->map.y * IMG_SZ;
	m_store->window.x = (m_store->map.x - 1) * IMG_SZ;
}
