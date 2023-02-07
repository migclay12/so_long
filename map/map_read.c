//WTF AM I DOING?!
//Guardar x e y en estructura
#include <fcntl.h>
#include "map.h"
#include "long_gnl/get_next_line.h"
//#include "../libft/libft.h"
/*
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp;
	size_t			i;

	i = 0;
	temp = (unsigned char *)b;
	while (i < len)
		temp[i++] = (unsigned char)c;
	return (b);
}
*/

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

char **ft_read_map (int fd, int height)
{
	char *map;
	char **full_map;
	int lines;

	//map = get_next_line(fd);
	lines = 0;
	while (map != NULL)
	{
		full_map[lines] = map;
		map = get_next_line(fd);
		lines++;
	}

	lines = 0;
	while (lines < height)
	{
		printf("%c", full_map[lines][2]);
		lines++;
	}
	return (full_map);
}

int	main(int argc, char **argv)
{
	int fd;
	t_map maps;
	char **idk;
	int fdy;
	//ft_memset(&maps, 0, sizeof(t_map));
	
	fd = open("map0.ber", O_RDONLY);
	ft_map_size(fd, &maps);
	close (fd);

	fdy = open("map0.ber", O_RDONLY);
	idk = ft_read_map(fdy, maps.y);
	close (fdy);
	return (0);
}