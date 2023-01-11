#include "move.h"

int ft_close ()
{
	exit(0);
}

int	main(void)
{
	t_program program;

	program.mlx = mlx_init();
	program.window.reference = mlx_new_window(program.mlx, 600, 400, "Hello world!");

	program.sprite = ft_new_sprite(program.mlx, "idle.xpm");
	program.sprite_position.x = 0;
	program.sprite_position.y = 0;

    mlx_put_image_to_window(program.mlx, program.window.reference,
		program.sprite.reference, program.sprite_position.x, program.sprite_position.y);
	
    mlx_key_hook(program.window.reference, *ft_input, &program);
    //mlx_loop_hook(program.mlx, *ft_update, &program);

	//mlx_key_hook(program.window.reference, close, &program);
	mlx_hook(program.window.reference, 17, 0, ft_close, 0);

	mlx_loop(program.mlx);
}