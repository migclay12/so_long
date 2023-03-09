/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:25:25 by miggonza          #+#    #+#             */
/*   Updated: 2023/03/09 20:27:33 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_close(void)
{
	exit(0);
}
//DO ERRORS FOR SPRITES
int	main(void)
{
	t_program	p;
	t_map		map;

	ft_all_map(&p, &map, "map0.ber");
	p.vars.mlx = mlx_init();
	p.vars.mlx_win = mlx_new_window(p.vars.mlx, p.window.x,
			p.window.y, "Mad Ting");
	ft_get_images(&p.sprite, &p.vars);
	ft_image_loop(&p.sprite, &p.vars, &p.map);
	ft_text_screen(&p);
	mlx_key_hook(p.vars.mlx_win, *ft_input, &p);
	mlx_hook(p.vars.mlx_win, 17, 0, ft_close, 0);
	p.time = 0;
	mlx_loop_hook(p.vars.mlx, ft_anim, &p);
	system("leaks -q so_long");
	mlx_loop(p.vars.mlx);
	return (0);
}
