#include "map.h"
#include "long_gnl/get_next_line.h"
#include <fcntl.h>

int val_char (char c)
{
    if (c == '1' || c == '0' || c == 'P' || c == 'C' || c == 'E')
        return (1);
    return (0);
}

int line_count (char *map)
{
    int lines;
    int file;

    file = open(map, O_RDONLY);

}