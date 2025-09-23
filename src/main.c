/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:25:25 by miggonza          #+#    #+#             */
/*   Updated: 2025/09/24 01:05:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_close(t_program *p)
{
	ft_cleanup_program(p);
	exit(0);
}

void	ft_print_error(char *str)
{
	ft_putstr("Error\n");
	ft_putstr(str);
	ft_putstr("\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	t_program	p;
	t_map		map;
	char		*file;

	file = "hola";
	if (argc != 2)
		ft_print_error("A map name has not been provided");
	if (argc == 2)
		file = argv[1];
	ft_all_map(&p, &map, file);
	ft_memset(p.sprites, 0, sizeof(p.sprites));
	p.vars.mlx = mlx_init();
	p.vars.mlx_win = mlx_new_window(p.vars.mlx, p.window.x,
			p.window.y, "So Long");
	ft_get_images(&p);
	ft_image_loop(&p, &p.vars, &p.map);
	ft_text_screen(&p);
	mlx_key_hook(p.vars.mlx_win, *ft_input, &p);
	mlx_hook(p.vars.mlx_win, 17, 0, ft_close, &p);
	p.time = 0;
	mlx_loop_hook(p.vars.mlx, ft_anim, &p);
	mlx_loop(p.vars.mlx);
	return (0);
}
