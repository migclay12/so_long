//ME GUARDA UN CARACTER DE MAS EN LA X
#include <fcntl.h>
#include "map.h"
#include "long_gnl/get_next_line.h"
//#include "../libft/libft.h"


void	ft_print_error(char *str)
{
    ft_putstr("Error\n");
    ft_putstr(str);
    ft_putstr("\n");
    exit(0);
}

void ft_map_size(int fd, t_map *size)
{
	char *map;

	map = get_next_line(fd);
	size->x = ft_strlen(map);
	while (map != NULL)
	{
		free(map);
		size->y++;
		map = get_next_line(fd);
		if (map && size->x != (int)ft_strlen(map))
			ft_print_error("lines are not the same length");
	}

	//printf("%d\n", size->x);
	//printf("%d\n", size->y);
}


char **ft_read_map(int fd, t_map *map)
{
	//char **full_map;
	int lines;

	map -> matrix = (char **)malloc(sizeof(char *) * map -> x + 1);
	lines = 0;
	while (lines < map -> x)
	{
		map -> matrix[lines] = get_next_line(fd);
		lines++;
	}
	return (map -> matrix);
}

int ft_map_name(char *map)
{
	int len;

	len = ft_strlen(map);
	if (map[len - 1] == 'r' && map[len - 2] == 'e'
		&& map[len - 3] == 'b' && map[len - 4] == '.')
		return (1);
	return (0);
}

//se puede hacer void?
int ft_wall_check(t_map *map)
{
	int i;
	int j;
	int top;
	int bot;

	i = 0;
	while (map->matrix[0][i] != '\n')
	{
		top = 1;
		if (map->matrix[0][i] != WALL)
			return (0);
		i++;
	}

	j = 0;
	while (map->matrix[map->y - 1][j] != '\n')
	{
		bot = 1;
		if (map->matrix[map->y - 1][j] != WALL)
			return (0);
		j++;
	}
	if (top == 1 && bot == 1)
		return (1);
	return (0);
}

int ft_mid_wall_check(t_map *map)
{
	int i;

	i = 1;
	while (i < map->y - 1)
	{
		if (map->matrix[i][0] != WALL || map->matrix[i][map->x - 2] != WALL)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_things things;
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
	
	//wall = ft_wall_check(&maps);
	//if (wall != 1)
		//ft_print_error("map is not surrounded by walls");

	wall = ft_mid_wall_check(&maps);
	if (wall != 1)
		ft_print_error("map is not surrounded by walls");
	return (0);
}