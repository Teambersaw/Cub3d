#include "cub3d.h"

int	ft_first_last(t_map *map, int j)
{
	int	i;

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

int	ft_verif_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
		i++;
	if (ft_first_last(map, 0) || ft_first_last(map, i - 1))
		return (1);
	if (ft_mid_map(map))
		return (1);
	return (0);
}

t_map	ft_parsing(int ac, char **av)
{
	int		fd;
	t_map	map;

	fd = ft_verif_name(ac, av);
	map = ft_init_map();
	if (ft_parse_elem(fd, &map.elem) || ft_verif_elem(&map.elem))
		return (close(fd), map);
	map.map = ft_parse_map(fd, &map);
	if (!map.map)
		return (close(fd), map);
	if (ft_verif_map(&map))
		return (close(fd), map);
	map.value = 1;
	close(fd);
	return (map);
}
