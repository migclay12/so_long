#include "../headers/so_long.h"
//gcc map_read.c long_gnl/get_next_line.c long_gnl/get_next_line_utils.c utils.c main.c

void ft_all_map(t_things *m_store, t_map *map)
{
	ft_memset(map, 0, sizeof(t_map));
	ft_memset(m_store, 0, sizeof(t_things));

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
}

int	main(void)
{
	t_things	m_store;
	t_map		map;

	ft_all_map(&m_store, &map);

	return (0);
}

/*
int	main(void)
{
	//t_things things;
	t_map map;
	int fd;
	char **idk;
	int name;
	int wall;
	ft_memset(&map, 0, sizeof(t_map));
	
	fd = open("map0.ber", O_RDONLY);
	ft_map_size(fd, &map);
	close (fd);

	fd = open("map0.ber", O_RDONLY);
	idk = ft_read_map(fd, &map);
	//printf("%c", idk[1][11]);
	close (fd);

	//printf("y %d", map.x);

	name = ft_map_name("map0.ber");
	if (name != 1)
		ft_print_error("map is not .ber file");
	
	wall = ft_wall_check(&map);
	if (wall != 1)
		ft_print_error("map is not surrounded by walls");
	
	wall = ft_mid_wall_check(&map);
	if (wall != 1)
		ft_print_error("map is not surrounded by walls");


	ft_val_collect(&map);

	int x;
	int y;
	ft_get_player(&map, &y, &x);
	//printf("x:%d\ny:%d", x, y);
	ft_loop_check(&map, y, x);
	ft_val_path(&map);
	//validate_loop(&map);

	//comprobar(&map, map.player.yp, map.player.xp);
	
	//printf("c %d", map.collectible.c);
	//printf("x %d", map.player.xp);
	//printf("y %d", map.player.yp);

	return (0);
}
*/