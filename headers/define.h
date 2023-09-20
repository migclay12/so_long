/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:06:40 by miggonza          #+#    #+#             */
/*   Updated: 2023/09/19 12:37:46 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

//HOOKS
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

//MAP
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

//NOT USED
# define ANIMATION_FRAMES 10

#endif