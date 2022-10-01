#include "cub3d.h"

char    *ft_stor(char *line, char *str)
{
    int i;
    int j;

    i = 0;
    if (!line || line[i] != ' ')
        return (NULL);
    while (line && line[i] == ' ')
        i++;
    if (!line || line[i] == '\0' || line[i] == '\n')
        return (NULL);
    j = i;
    while (line && line[i] && line[i] != '\n')
        i++;
    if (!line || !line[i])
        return (NULL);
    if (str)
        free(str);
    str = ft_strdup_2(line + j, '\n');
    return (str);
}

char    **ft_stor_tab(char *line, char **tab)
{
    char    *s;
    int     i;

    i = 0;
    if (!line || line[i] != ' ')
        return (NULL);
    while (line && line[i] == ' ')
        i++;
    tab = ft_split(line + i, ',');
    if (!tab)
        return (NULL);
    i = 0;
    while (tab[i])
        i++;
    if (i != 3)
        return (ft_free_tab(tab), NULL);
    i = 0;
    while (line[i] && line[i] != '\n')
        i++;
    if (line[i] == '\0')
         return (ft_free_tab(tab), NULL);
    s = ft_strdup_2(tab[2], '\n');
    free(tab[2]);
    tab[2] = s;
    return (tab);
}

int ft_elem_cmp(char *line, t_elem *elem)
{
    if (!ft_strncmp(line, "NO", 2))
        elem->NO = ft_stor(line + 2, elem->NO);
    else if (!ft_strncmp(line, "EA", 2))
        elem->EA = ft_stor(line + 2, elem->EA);
    else if (!ft_strncmp(line, "SO", 2))
        elem->SO = ft_stor(line + 2, elem->SO);
    else if (!ft_strncmp(line, "WE", 2))
        elem->WE = ft_stor(line + 2, elem->WE);
    else if (!ft_strncmp(line, "F", 1))
        elem->F = ft_stor_tab(line + 1, elem->F);
    else if (!ft_strncmp(line, "C", 1))
        elem->C = ft_stor_tab(line + 1, elem->C);
    else
        return (1);
    elem->nb_elem += 1;
    return (0);
}

int ft_parse_line(char *line, t_elem *elem)
{
    int i;

    i = 0;
    while (line[i] && line[i] == ' ')
        i++;
    if (line[i] == '\0')
        return (1);
    if (line[i] == '\n')
        return (1);
    if (ft_elem_cmp(&line[i], elem))
        return (1);
    return (0); 
}

int ft_parse_elem(int fd, t_elem *elem)
{
    char    *line;

    line = get_next_line(fd);
    if (!line)
        return (1);
    while (line != NULL)
    {
        if (line[0] == '\n')
        {
            free(line);
            line = get_next_line(fd);
            continue ;
        }
        if (ft_parse_line(line, elem))
            return (free(line), 1);
        free(line);
        if (elem->nb_elem >= 6)
            break ;
        line = get_next_line(fd);
    }
    return (0);
}

int ft_first_last(t_map *map, int j)
{
    int i;

    i = 0;
    while (map->map[j][i])
    {
        if (map->map[j][i] == '0' || map->map[j][i] == map->player)
            return (1);
        if (map->map[j][i] == '1')
            map->map[j][i] = 'm';
        i++;
    }
    i = 0;
    while (map->map[i])
    {
        j = 0;
        while (map->map[i][j] == ' ')
            j++;
        if (map->map[i][j] != '1' && map->map[i][j] != 'm')
            return (1);
        map->map[i][j] = 'm';
        i++;
    }
    return (0);
}

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

int ft_verif_map(t_map *map)
{
    int i;

    i = 0;
    while (map->map[i])
        i++;
     if (ft_first_last(map, 0) || ft_first_last(map, i - 1))
        return (1);
    if (ft_mid_map(map))
        return (1);
    return (0);
}

int ft_parsing(int fd, t_elem *elem)
{
    t_map   map;

    if (ft_parse_elem(fd, elem) || ft_verif_elem(elem))
        return (1);
    map = ft_init_map();    
    map.map = ft_parse_map(fd, &map);
    if (!map.map)
        return (1);
    if (ft_verif_map(&map))
        return (ft_free_tab(map.map), 1);
    print_tabb(map.map);
    ft_free_tab(map.map);
    return (0);
}