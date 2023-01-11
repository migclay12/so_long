#ifndef MOVE_H
# define MOVE_H

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef ESC
# define ESC 53
#endif

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 10
# endif

//STRUCTURES

typedef struct	s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct	s_window {
	void		*reference;
	t_vector	size;
}				t_window;

typedef struct	s_image {
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

typedef struct	s_program {
	void		*mlx;
	t_window	window;
	t_image		sprite;
	t_vector	sprite_position;
}				t_program;

//FUNCTIONS

t_image	ft_new_sprite(void *mlx, char *path);
int ft_input(int key, void *param);
int ft_update (void *param);
t_window	ft_new_window(void *mlx, int widht, int height, char *name);
int	close(int keycode, t_program *vars);

#endif