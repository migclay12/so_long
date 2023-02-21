/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:33:09 by miggonza          #+#    #+#             */
/*   Updated: 2023/02/21 18:59:26 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_open_file(char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	return (fd);
}

void	ft_all_map(t_program *m_store, t_map *map)
{
	int	name;

	ft_memset(map, 0, sizeof(t_map));
	ft_memset(m_store, 0, sizeof(t_program));
	ft_map_size(ft_open_file("map0.ber"), map);
	ft_map_size(ft_open_file("map0.ber"), &m_store->map);
	map->matrix = ft_read_map(ft_open_file("map0.ber"), map);
	m_store->map.matrix = ft_read_map(ft_open_file("map0.ber"), &m_store->map);
	name = ft_map_name("map0.ber");
	if (name != 1)
		ft_print_error("map is not .ber file");
	ft_full_wall_check(map);
	ft_val_collect(&m_store->map, &m_store->player);
	ft_errors(m_store);
	ft_validate(map);
	m_store->window.y = m_store->map.y * 64;
	m_store->window.x = (m_store->map.x - 1) * 64;
}
