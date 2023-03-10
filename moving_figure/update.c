/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:17:48 by miggonza          #+#    #+#             */
/*   Updated: 2023/03/10 15:46:01 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_anim(t_program *p)
{
	p->time++;
	if (p->time % 600 == 0)
		ft_win(p);
	if (p->time % 1500 == 0)
		ft_die(p);
	return (0);
}

void	ft_win(t_program *p)
{
	static int	cont = 0;

	if (p->map.comp.c == 0)
	{
		if (cont < 20)
		{
			mlx_put_image_to_window(p->vars.mlx, p->vars.mlx_win,
				p->sprite.floor, p->map.comp.exit_x * IMG_SZ,
				p->map.comp.exit_y * IMG_SZ);
			mlx_put_image_to_window(p->vars.mlx, p->vars.mlx_win,
				p->sprite.sprites[EXIT_SPRITE][cont], p->map.comp.exit_x * IMG_SZ,
				p->map.comp.exit_y * IMG_SZ);
				//p->sprite.exit[cont], p->map.comp.exit_x * IMG_SZ,
			cont++;
		}
		p->sprite.m_exit = p->sprite.exit[19];
	}
}

void	ft_die(t_program *p)
{
	static int	cont = 0;
	if (p->sprite.player == p->sprite.dead[0])
	{
		if (cont < 6)
		{
			mlx_put_image_to_window(p->vars.mlx, p->vars.mlx_win,
				p->sprite.floor, p->player.x * IMG_SZ,
				p->player.y * IMG_SZ);
			mlx_put_image_to_window(p->vars.mlx, p->vars.mlx_win,
				p->sprite.dead[cont], p->player.x * IMG_SZ,
				p->player.y * IMG_SZ);
			cont++;
		}
		//p->sprite.player = p->sprite.dead[5];
	}
}


/*
static void	player_animation(t_player *player)
{
	if (player->current_img == player->action_img
		&& player->framecount >= player->action_frames)
	{
		player->current_img = player->idle_img_1;
	}
	else if (player->framecount == player->idle_frames)
	{
		player->current_img = player->idle_img_0;
	}
	else if (player->framecount >= player->idle_frames * 2)
	{
		player->current_img = player->idle_img_1;
		player->framecount = 0;
	}
	player->framecount += 1;
}
*/
/*
static void	player_idle(t_player *player)
{
	int frames;

	frames = 0;
	if (player->player == player->idle3
		&& frames >= ANIMATION_FRAMES)
	{
		player->player = player->idle0;
	}
	else if (player->framecount == player->idle_frames)
	{
		player->current_img = player->idle_img_0;
	}
	else if (player->framecount >= player->idle_frames * 2)
	{
		player->current_img = player->idle_img_1;
		player->framecount = 0;
	}
	player->framecount += 1;
}


int	update(t_program *game)
{
	player_idle(&game->player);
	//collec_animation(&game->collects_imgs);
	//effect_animation(&game->effect);
	//enemy_animation(&game->enemy_imgs);
	//render(*game);
	return (1);
}
*/
