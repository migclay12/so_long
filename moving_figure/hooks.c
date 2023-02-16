#include "../headers/so_long.h"

int ft_input(int key, t_program *program)
{
	if (key == D)
		ft_move(program, 1, 0);
	else if (key == A)
		ft_move(program, -1, 0);
	else if (key == S)
		ft_move(program, 0, 1);
	else if (key == W)
		ft_move(program, 0, -1);
	else if (key == ESC)
		exit (0);
	printf("Key -> %d\n", key);
	return (0);
}

void ft_move(t_program *program, int x, int y)
{
	if (program->map.matrix[program->player.y + y][program->player.x + x] == EMPTY
		|| program->map.matrix[program->player.y + y][program->player.x + x] == COLLECTIBLE)
	{
		program->map.matrix[program->player.y][program->player.x] = EMPTY;
		program->map.matrix[program->player.y + y][program->player.x + x] = START;
		program->player.y += y;
		program->player.x += x;
	}
	ft_put_images(&program->sprite, &program->vars, &program->map);
}

//ADDS MOVEMENT TO THE CHARACTER
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