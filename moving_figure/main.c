#include "../headers/so_long.h"

int ft_close ()
{
	exit(0);
}

void ft_all_map(t_program *m_store, t_map *map)
{
	ft_memset(map, 0, sizeof(t_map));
	ft_memset(m_store, 0, sizeof(t_program));

	ft_map_size(open("map0.ber", O_RDONLY), map);
	ft_map_size(open("map0.ber", O_RDONLY), &m_store->map);

	map->matrix = ft_read_map(open("map0.ber", O_RDONLY), map);
	m_store->map.matrix = ft_read_map(open("map0.ber", O_RDONLY), &m_store->map);

	int name;
	name = ft_map_name("map0.ber");
	if (name != 1)
		ft_print_error("map is not .ber file");

	ft_full_wall_check(map);
	ft_val_collect(&m_store->map, &m_store->player);

	ft_validate(map);
	m_store->window.y = m_store->map.y * 64;
	m_store->window.x = (m_store->map.x - 1) * 64;
}

int	main(void)
{
	t_program	program;
	t_map		map;

	ft_all_map(&program, &map);
	printf("xp %d\n", program.player.x);
	printf("yp %d\n", program.player.y);
	printf("y %d\n", program.window.y);
	printf("x %d\n", program.window.x);
	
	program.vars.mlx = mlx_init();
	
	program.vars.mlx_win = mlx_new_window(program.vars.mlx, program.window.x, program.window.y, "Mad Ting");

	ft_get_images(&program.sprite, &program.vars);
	ft_put_images(&program.sprite, &program.vars, &program.map);

/*
	program.player = ft_new_sprite(program.mlx, PLAYER_XPM);
	program.player_position.x = program.player_position.x * 64;
	program.player_position.y = program.player_position.y * 64;

	mlx_put_image_to_window(program.mlx, program.window.reference,
		program.player.reference, program.player_position.x, program.player_position.y);
*/
    mlx_key_hook(program.vars.mlx_win, *ft_input, &program);
    //mlx_loop_hook(program.mlx, *ft_update, &program);

	//mlx_key_hook(program.window.reference, close, &program);
	mlx_hook(program.vars.mlx_win, 17, 0, ft_close, 0);

	mlx_loop(program.vars.mlx);
}