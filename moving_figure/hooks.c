/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:17:08 by miggonza          #+#    #+#             */
/*   Updated: 2023/02/21 19:29:12 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_input(int key, t_program *p)
{
	if (key == D || key == RIGHT)
		ft_move(p, 1, 0);
	if (key == A || key == LEFT)
		ft_move(p, -1, 0);
	if (key == S || key == DOWN)
		ft_move(p, 0, 1);
	if (key == W || key == UP)
		ft_move(p, 0, -1);
	if (key == ESC)
		exit (0);
	//printf("Key -> %d\n", key);
	return (0);
}

void	ft_move(t_program *p, int x, int y)
{
	if (p->map.matrix[p->player.y + y][p->player.x + x] == EXIT
		&& p->map.collectible.c == 0)
		ft_close();
	if (p->map.matrix[p->player.y + y][p->player.x + x] == ENEMY)
		ft_close();
	if (p->map.matrix[p->player.y + y][p->player.x + x] == EMPTY
		|| p->map.matrix[p->player.y + y][p->player.x + x] == COLLECTIBLE)
	{
		if (p->map.matrix[p->player.y + y][p->player.x + x] == COLLECTIBLE)
			p->map.collectible.c--;
		p->map.matrix[p->player.y][p->player.x] = EMPTY;
		p->map.matrix[p->player.y + y][p->player.x + x] = PLAYER;
		p->player.y += y;
		p->player.x += x;
		p->moves++;
		printf("FU %d\n", p->moves);
	}
	if (p->map.collectible.c == 0)
		p->sprite.exit = mlx_xpm_file_to_image(p->vars.mlx, OPEN_XPM,
				&p->vars.img_x, &p->vars.img_y);
	ft_image_loop(&p->sprite, &p->vars, &p->map);
	
}

//ADDS MOVEMENT TO THE CHARACTER
/*
int ft_update (void *param)
{
	t_program *program = (t_program *)param;

	static int frame;

	frame++;
	if (frame == ANIMATION_FRAMES)
		program->player.y += 1;
	else if (frame >= ANIMATION_FRAMES * 2)
	{
		program->player.y -= 1;
		frame = 0;
	}

	mlx_put_image_to_window(program->vars.mlx, program->window.reference, program->sprite.player, 
			program->player.x, program->player.y);

	return (0);
}
*/