#include "move.h"

int ft_input(int key, void *param)
{
	t_program *program = (t_program *)param;

	// mlx function that clears the window
	mlx_clear_window(program->mlx, program->window.reference);

	if (key == 2)
		program->sprite_position.x += program->sprite.size.x;
	else if (key == 0)
		program->sprite_position.x -= program->sprite.size.x;
	else if (key == 1)
		program->sprite_position.y += program->sprite.size.y;
	else if (key == 13)
		program->sprite_position.y -= program->sprite.size.y;
	else if (key == ESC)
		exit (0);

	mlx_put_image_to_window(program->mlx, program->window.reference, program->sprite.reference, 
			program->sprite_position.x, program->sprite_position.y);

	printf("Key -> %d\n", key);

	return (0);
}

/*
int ft_update (void *param)
{
	t_program *program = (t_program *)param;

	static int frame;

	frame++;
	if (frame == ANIMATION_FRAMES)
		program->sprite_position.y += 1;
	else if (frame >= ANIMATION_FRAMES * 2)
	{
		program->sprite_position.y -= 1;
		frame = 0;
	}

	mlx_put_image_to_window(program->mlx, program->window.reference, program->sprite.reference, 
			program->sprite_position.x, program->sprite_position.y);

	return (0);
}
*/