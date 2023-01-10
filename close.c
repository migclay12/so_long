#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

#define ESC 53

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
};

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	close(int keycode, t_vars *vars)
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
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
    mlx_key_hook(vars.win, close, &vars);
	//mlx_hook(vars.win, 02, 0, close, &vars);
	mlx_loop(vars.mlx);
}