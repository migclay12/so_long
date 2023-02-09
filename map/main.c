#include "../headers/so_long.h"
//gcc map_read.c long_gnl/get_next_line.c long_gnl/get_next_line_utils.c utils.c main.c

int	main(void)
{
	//t_things things;
	t_map maps;
	int fd;
	char **idk;
	int name;
	int wall;
	//ft_memset(&maps, 0, sizeof(t_map));
	
	fd = open("map0.ber", O_RDONLY);
	ft_map_size(fd, &maps);
	close (fd);

	fd = open("map0.ber", O_RDONLY);
	idk = ft_read_map(fd, &maps);
	//printf("%c", idk[1][11]);
	close (fd);

	name = ft_map_name("map0.ber");
	if (name != 1)
		ft_print_error("map is not .ber file");
	
	wall = ft_wall_check(&maps);
	if (wall != 1)
		ft_print_error("map is not surrounded by walls");
	
	wall = ft_mid_wall_check(&maps);
	if (wall != 1)
		ft_print_error("map is not surrounded by walls");

	return (0);
}