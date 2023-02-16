#include "../headers/so_long.h"

void ft_get_images(t_sprite *sprite, t_vars *vars)
{
	int img_x;
	int img_y;
	sprite->floor = mlx_xpm_file_to_image(vars->mlx, TILE_XPM, &img_x, &img_y);
	sprite->wall = mlx_xpm_file_to_image(vars->mlx, WALL_XPM, &img_x, &img_y);
	sprite->collectiblle = mlx_xpm_file_to_image(vars->mlx, COLLECTIBLE_XPM, &img_x, &img_y);
	sprite->exit = mlx_xpm_file_to_image(vars->mlx, EXIT_XPM, &img_x, &img_y);
	sprite->player = mlx_xpm_file_to_image(vars->mlx, PLAYER_XPM, &img_x, &img_y);
}

void ft_put_images(t_sprite *sprite, t_vars *vars, t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map->matrix[y])
	{
		while (map->matrix[y][x] != '\n')
		{
			//printf("%p\n", vars->mlx_win);

			mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					sprite->floor, x * 64, y * 64);
			if (map->matrix[y][x] == WALL)
				mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					sprite->wall, x * 64, y * 64);
			if (map->matrix[y][x] == COLLECTIBLE)
				mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					sprite->collectiblle, x * 64, y * 64);
			if (map->matrix[y][x] == EXIT)
				mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					sprite->exit, x * 64, y * 64);
			if (map->matrix[y][x] == START)
				mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					sprite->player, x * 64, y * 64);
			x++;
		}
		y++;
		x = 0;
	}
}

/*
t_window	ft_new_window(void *mlx, int widht, int height, char *name)
{
	t_window	window;

	// This mlx function creates a returns a pointer
	//to a new window with a given size and name 
	window.reference = mlx_new_window(mlx, widht, height, name);
	window.x = widht;
	window.y = height;

	// Now we 'hook' the function ft_close() to the closing window event
	//mlx_key_hook(window.reference, close, &window);
	mlx_hook(window.reference, 17, 0, ft_close, 0);

	return (window);
}
*/