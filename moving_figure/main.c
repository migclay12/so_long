#include "../headers/so_long.h"

int ft_close ()
{
	exit(0);
}

int	main(void)
{
	t_program program;
	//t_map maps;

	program.mlx = mlx_init();
	program.window.reference = mlx_new_window(program.mlx, 1900, 1080, "Hello world!");

	program.player = ft_new_sprite(program.mlx, PLAYER);
	program.player_position.x = 0; //maps.player.xp;
	program.player_position.y = 0; //maps.player.yp;

	program.floor = ft_new_sprite(program.mlx, TILE);
		program.floor_position.x = 38;
		program.floor_position.y = 0;
    
	mlx_put_image_to_window(program.mlx, program.window.reference,
		program.player.reference, program.player_position.x, program.player_position.y);

	//mlx_put_image_to_window(program.mlx, program.window.reference,
		//program.floor.reference, program.floor_position.x, program.floor_position.y);

    mlx_key_hook(program.window.reference, *ft_input, &program);
    //mlx_loop_hook(program.mlx, *ft_update, &program);

	//mlx_key_hook(program.window.reference, close, &program);
	mlx_hook(program.window.reference, 17, 0, ft_close, 0);

	mlx_loop(program.mlx);
}