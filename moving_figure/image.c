#include "move.h"

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;
	
	img.reference = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels  = mlx_get_data_addr(img.reference, &img.bits_per_pixel, &img.line_size, &img.endian);
	return (img);
}