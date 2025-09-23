/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:00:00 by miggonza          #+#    #+#             */
/*   Updated: 2025/01/27 12:00:00 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	ft_free_map_matrix(char **matrix, int height)
{
	int	i;

	if (!matrix)
		return;
	i = 0;
	while (i < height)
	{
		if (matrix[i])
			free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	ft_free_sprites(t_program *p)
{
	int	i;
	int	j;

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 21)
		{
			if (p->sprites[i][j])
			{
				mlx_destroy_image(p->vars.mlx, p->sprites[i][j]);
				p->sprites[i][j] = NULL;
			}
			j++;
		}
		i++;
	}
}

void	ft_cleanup_program(t_program *p)
{
	if (p->map.matrix)
		ft_free_map_matrix(p->map.matrix, p->map.y);
	ft_free_sprites(p);
	if (p->vars.mlx_win)
		mlx_destroy_window(p->vars.mlx, p->vars.mlx_win);
	if (p->vars.mlx)
		mlx_destroy_display(p->vars.mlx);
}
