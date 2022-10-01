#include "cub3d.h"

int ft_exist_tab(t_map *map, size_t x, size_t y)
{
    if ((ft_strlen(map->map[x - 1]) - 1) < y || (ft_strlen(map->map[x + 1]) - 1) < y)
        return (1);
    return (0);
}

void    ft_create_wall(t_map *map, size_t x, size_t y)
{
    if (ft_exist_tab(map, x, y))
        map->map[x][y] = 'm';
    else if (map->map[x - 1][y] == ' ' || map->map[x + 1][y] == ' '
        || map->map[x][y - 1] == ' ' || map->map[x][y + 1] == ' ')
        map->map[x][y] = 'm';
}

int ft_open_map(t_map *map, size_t x, size_t y)
{
    size_t i;

    i = 0;
    while (map->map[i])
        i++;
    if (x == 0 || x == (i - 1) || y == 0 || y == ft_strlen(map->map[x]) - 1)
    {
        if (map->map[x][y] == '0' || map->map[x][y] == map->player)
            return (1);
        return (0);
    }
    if (map->map[x][y] == '1' || map->map[x][y] == 'm')
        ft_create_wall(map, x, y);
    else if (map->map[x][y] == '0' || map->map[x][y] ==  map->player)
    {
        if (ft_exist_tab(map, x, y))
            return (1);
        if (map->map[x - 1][y] == ' ' || map->map[x + 1][y] == ' '
            || map->map[x][y - 1] == ' ' || map->map[x][y + 1] == ' ')
            return (1);
    }
    return (0);
}

int ft_mid_map(t_map *map)
{
    size_t x;
    size_t y;

    x = 0;
    while (map->map[x])
    {
        y = 0;
        while (map->map[x][y])
        {
            if (ft_open_map(map, x, y))
                return (1);
            y++;
        }
        if (map->map[x][y - 1] == '1')
            map->map[x][y - 1] = 'm';
        x++;
    }
    return (0);
}