/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:06:40 by miggonza          #+#    #+#             */
/*   Updated: 2023/03/10 15:44:43 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

//hooks
# define ESC	53
# define W		13
# define A		0
# define S		1
# define D		2
# define UP		126
# define RIGHT	124
# define DOWN	125
# define LEFT	123
# define IMG_SZ 64

//map
# define VAL_CHAR		"01CEPB"
# define EMPTY			'0'
# define WALL			'1'
# define COLLECTIBLE	'C'
# define EXIT_CHAR		'E'
# define PLAYER			'P'
# define ENEMY			'B'
# define DEAD			'D'
# define EXIT_SPRITE    0

# define ANIMATION_FRAMES 10

//sprites
# define TILE_XPM			"../sprites/tile.xpm"
# define COLLECTIBLE_XPM	"../sprites/skull.xpm"
# define ENEMY_XPM			"../sprites/knight.xpm"
# define EXIT_XPM			"../sprites/main_exit.xpm"
# define WALL0_XPM			"../sprites/wall0.xpm"
# define WALL1_XPM			"../sprites/wall1.xpm"
# define WALL2_XPM			"../sprites/wall2.xpm"
# define WALL3_XPM			"../sprites/wall3.xpm"

//# define PLAYER_XPM		"../sprites/player/bandit.xpm"
# define KNIGHT_XPM			"../sprites/player/pidle0.xpm"
# define PLAYER0_XPM		"../sprites/player/pidle0.xpm"
# define PLAYER1_XPM		"../sprites/player/pidle1.xpm"
# define PLAYER2_XPM		"../sprites/player/pidle2.xpm"
# define PLAYER3_XPM		"../sprites/player/pidle3.xpm"
# define PLAYERL0_XPM		"../sprites/player/pidlel0.xpm"

/*
# define EXIT0				"../sprites/exit/exit0.xpm"
# define EXIT1				"../sprites/exit/exit1.xpm"
# define EXIT2				"../sprites/exit/exit2.xpm"
# define EXIT3			    "../sprites/exit/exit3.xpm"
# define EXIT4			    "../sprites/exit/exit4.xpm"
# define EXIT5			    "../sprites/exit/exit5.xpm"
# define EXIT6			    "../sprites/exit/exit6.xpm"
# define EXIT7			    "../sprites/exit/exit7.xpm"
# define EXIT8			    "../sprites/exit/exit8.xpm"
# define EXIT9			    "../sprites/exit/exit9.xpm"
# define EXIT10			    "../sprites/exit/exit10.xpm"
# define EXIT11			    "../sprites/exit/exit11.xpm"
# define EXIT12			    "../sprites/exit/exit12.xpm"
# define EXIT13			    "../sprites/exit/exit13.xpm"
# define EXIT14			    "../sprites/exit/exit14.xpm"
# define EXIT15			    "../sprites/exit/exit15.xpm"
# define EXIT16			    "../sprites/exit/exit16.xpm"
# define EXIT17			    "../sprites/exit/exit17.xpm"
# define EXIT18			    "../sprites/exit/exit18.xpm"
# define EXIT19			    "../sprites/exit/exit19.xpm"
*/

#endif