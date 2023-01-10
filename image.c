#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

#define ESC 53

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

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;
	
	img.reference = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels  = mlx_get_data_addr(img.reference, &img.bits_per_pixel, &img.line_size, &img.endian);
	return (img);
}

int	close(int keycode, t_program *vars)
{
    printf("%d\n", keycode);
    if (keycode == ESC)
        exit (0);
    (void) vars;
	//mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	main(void)
{
	t_program program;

	program.mlx = mlx_init();
	program.window.reference = mlx_new_window(program.mlx, 1980, 1080, "Hello world!");

	program.sprite = ft_new_sprite(program.mlx, "block.xpm");
	program.sprite_position.x = 45;
	program.sprite_position.y = 76;

    mlx_put_image_to_window(program.mlx, program.window.reference,
		program.sprite.reference, program.sprite_position.x, program.sprite_position.y);
	mlx_key_hook(program.window.reference, close, &program);
	mlx_loop(program.mlx);
}