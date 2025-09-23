/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:06:40 by miggonza          #+#    #+#             */
/*   Updated: 2025/09/23 19:18:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

//HOOKS (Linux key codes)
# define ESC	65307
# define W		119
# define A		97
# define S		115
# define D		100
# define UP		65362
# define RIGHT	65363
# define DOWN	65364
# define LEFT	65361
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