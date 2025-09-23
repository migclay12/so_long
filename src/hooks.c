/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:17:08 by miggonza          #+#    #+#             */
/*   Updated: 2025/09/24 00:23:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	ft_text_screen(t_program *p)
{
	char	*c;

	c = ft_itoa(p->moves);
	mlx_string_put(p->vars.mlx, p->vars.mlx_win,
		(p->window.x / 2) - 90, 50, 0xffffff, "Number of moves: ");
	mlx_string_put(p->vars.mlx, p->vars.mlx_win,
		(p->window.x / 2) + 80, 50, 0xffffff, c);
	ft_printf("Moves: %s\n", c);
	free(c);
}

int	ft_input(int key, t_program *p)
{
	if (key == D || key == RIGHT)
	{
		p->sprites[PLAYER_SP][0] = p->sprites[PLAYER_SP][1];
		ft_move(p, 1, 0);
	}
	if (key == A || key == LEFT)
	{
		p->sprites[PLAYER_SP][0] = p->sprites[PLAYERL_SP][0];
		ft_move(p, -1, 0);
	}
	if (key == S || key == DOWN)
		ft_move(p, 0, 1);
	if (key == W || key == UP)
		ft_move(p, 0, -1);
	if (key == ESC)
		ft_close(p);
	return (0);
}

void	ft_move(t_program *p, int x, int y)
{
	if (p->map.matrix[p->player.y + y][p->player.x + x] == EXIT
		&& p->map.comp.c == 0)
		ft_close(p);
	if (p->map.matrix[p->player.y + y][p->player.x + x] == ENEMY)
		p->sprites[PLAYER_SP][0] = p->sprites[DEAD_SP][0];
	if (p->map.matrix[p->player.y + y][p->player.x + x] == EMPTY
		|| p->map.matrix[p->player.y + y][p->player.x + x] == COLLECTIBLE)
	{
		if (p->map.matrix[p->player.y + y][p->player.x + x] == COLLECTIBLE)
			p->map.comp.c--;
		p->map.matrix[p->player.y][p->player.x] = EMPTY;
		p->map.matrix[p->player.y + y][p->player.x + x] = PLAYER;
		p->player.y += y;
		p->player.x += x;
		p->moves++;
	}
	ft_image_loop(p, &p->vars, &p->map);
	ft_text_screen(p);
}

/*
ADDS MOVEMENT TO THE CHARACTER
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