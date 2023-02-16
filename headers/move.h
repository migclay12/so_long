#ifndef MOVE_H
# define MOVE_H

//STRUCTURES

typedef struct s_collect
{
	int	e;
	int	p;
	int c;
}	t_collect;

typedef struct s_player
{
	int x;
	int y;
}	t_player;

typedef struct s_map
{
	char		**matrix;
	int			x;
	int			y;
	t_collect	collectible;
}	t_map;

typedef struct	s_window {
	void		*reference;
	int			x;
	int			y;
}	t_window;

typedef struct s_vars {
	void	*mlx;
	void	*mlx_win;
	//int		img_w;
	//int		img_h;
	//int		win_w;
	//int		win_h;
}	t_vars;

typedef struct s_sprite {
	void	*floor;
	void	*wall;
	void	*collectiblle;
	void	*exit;
	void	*player;
}	t_sprite;

typedef struct	s_image {
	void		*reference;
	t_window	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

typedef struct	s_program {
	t_window	window;
	//DO I USE IMAGE?
	t_image		image;
	t_player	player;
	t_map		map;
	t_vars		vars;
	t_sprite	sprite;
}	t_program;


//FUNCTIONS

t_image	ft_new_sprite(void *mlx, char *path);
int ft_input(int key, t_program *program);
//int ft_update (void *param);
t_window	ft_new_window(void *mlx, int widht, int height, char *name);
//int	close(int keycode, t_program *vars);

void ft_get_images(t_sprite *sprite, t_vars *vars);

void ft_get_images(t_sprite *sprite, t_vars *vars);
void ft_put_images(t_sprite *sprite, t_vars *vars, t_map *map);
void ft_move(t_program *program, int x, int y);

#endif