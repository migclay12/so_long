#include "../headers/so_long.h"

void ft_val_collect(t_map *map)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (map->matrix[y])
    {
        while (map->matrix[y][x] != '\n')
        {
            if (map->matrix[y][x] == COLLECTIBLE)
                map->collectible.c++;
            if (map->matrix[y][x] == EXIT)
                map->collectible.e++;
            if (map->matrix[y][x] == START)
            {
                map->collectible.p++;
                map->player.xp = x;
                map->player.yp = y;
            }
            x++;
        }
        y++;
        x = 0;
    }
    if(map->collectible.e != 1 || map->collectible.p != 1)
        ft_print_error("Player and/or exit are not correct");
    if(map->collectible.c < 1)
        ft_print_error("Not enough collectibles");
}
