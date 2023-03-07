/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:06:40 by miggonza          #+#    #+#             */
/*   Updated: 2023/03/07 18:17:15 by miggonza         ###   ########.fr       */
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
# define EXIT			'E'
# define PLAYER			'P'
# define ENEMY			'B'

# define ANIMATION_FRAMES 10

//sprites
# define TILE_XPM			"../sprites/grass.xpm"
# define PLAYER_XPM			"../sprites/player.xpm"
# define COLLECTIBLE_XPM	"../sprites/collect.xpm"
# define WALL0_XPM			"../sprites/wall0.xpm"
# define WALL1_XPM			"../sprites/wall1.xpm"
# define WALL2_XPM			"../sprites/wall2.xpm"
# define WALL3_XPM			"../sprites/wall3.xpm"
# define EXIT_XPM			"../sprites/exit0.xpm"
# define OPEN_XPM           "../sprites/open.xpm"
# define ENEMY_XPM			"../sprites/enemy.xpm"

#endif