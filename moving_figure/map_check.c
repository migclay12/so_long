/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:33:09 by miggonza          #+#    #+#             */
/*   Updated: 2023/02/23 13:39:14 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_open_file(char *map)
{
	if (!ft_map_name(map))
		ft_print_error("The file map is not .ber");
	return (open(map, O_RDONLY));
}

//void	ft_all_map(t_program *m_store, t_map *map)
void	ft_all_map(t_program *m_store, t_map *map, char *name)
{
	ft_memset(map, 0, sizeof(t_map));
	ft_memset(m_store, 0, sizeof(t_program));
	ft_map_size(ft_open_file(name), map);
	ft_map_size(ft_open_file(name), &m_store->map);
	map->matrix = ft_read_map(ft_open_file(name), map);
	m_store->map.matrix = ft_read_map(ft_open_file(name), &m_store->map);
	ft_wall_error(map);
	ft_val_collect(&m_store->map, &m_store->player);
	ft_char_error(m_store);
	ft_validate(map);
	m_store->window.y = m_store->map.y * 64;
	m_store->window.x = (m_store->map.x - 1) * 64;
}
