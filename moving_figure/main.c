/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:25:25 by miggonza          #+#    #+#             */
/*   Updated: 2023/09/18 13:59:27 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_close(void)
{
	exit(0);
}

void	ft_print_error(char *str)
{
	ft_putstr("Error\n");
	ft_putstr(str);
	ft_putstr("\n");
	exit(0);
}
//MAKE AN IF FOR MAX WINDOW SIZE?!
//MAX AMMOUNT IN MAP2
//PIDLER123 NOT USED
//MAZE! == FULL SIZE
//CLEAN HEADERS

int	main(void)
{
	t_program	p;
	t_map		map;

	ft_all_map(&p, &map, "map0.ber");
	p.vars.mlx = mlx_init();
	p.vars.mlx_win = mlx_new_window(p.vars.mlx, p.window.x,
			p.window.y, "Mad Ting");
	ft_get_images(&p);
	ft_image_loop(&p, &p.vars, &p.map);
	ft_text_screen(&p);
	mlx_key_hook(p.vars.mlx_win, *ft_input, &p);
	mlx_hook(p.vars.mlx_win, 17, 0, ft_close, 0);
	p.time = 0;
	mlx_loop_hook(p.vars.mlx, ft_anim, &p);
	mlx_loop(p.vars.mlx);
	return (0);
}
//loop_hook
//system("leaks -q so_long");
//loop