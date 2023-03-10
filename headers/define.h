/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:06:40 by miggonza          #+#    #+#             */
/*   Updated: 2023/03/10 16:34:28 by miggonza         ###   ########.fr       */
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
# define VAL_CHAR		"01CEPK"
# define EMPTY			'0'
# define WALL			'1'
# define COLLECTIBLE	'C'
# define EXIT			'E'
# define PLAYER			'P'
# define ENEMY			'K'
# define DEAD			'D'

//ADD A PLAYER IN PLAYER
//ADD M_EXIT IN EXIT
# define FLOOR_SP		0
# define WALL_SP		1
# define PLAYER_SP		2
# define PLAYERL_SP		3
# define EXIT_SP		4
# define ENEMY_SP		5
# define COLL_SP		6
# define DEAD_SP		7

/*
//sprites
# define TILE_XPM			"../sprites/tile.xpm"
# define COLLECTIBLE_XPM	"../sprites/skull.xpm"
# define ENEMY_XPM			"../sprites/knight.xpm"
# define EXIT_XPM			"../sprites/main_exit.xpm"

//# define PLAYER_XPM		"../sprites/player/bandit.xpm"
# define KNIGHT_XPM			"../sprites/player/pidle0.xpm"
# define PLAYER0_XPM		"../sprites/player/pidle0.xpm"
# define PLAYER1_XPM		"../sprites/player/pidle1.xpm"
# define PLAYER2_XPM		"../sprites/player/pidle2.xpm"
# define PLAYER3_XPM		"../sprites/player/pidle3.xpm"
# define PLAYERL0_XPM		"../sprites/player/pidlel0.xpm"
*/
# define ANIMATION_FRAMES 10

#endif