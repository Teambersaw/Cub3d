#include "cub3d.h"

int	ft_all_space(t_map *map, int i)
{
	size_t	j;

	j = 0;
	while (map->map[i][j])
	{
		if (map->map[i][j] != ' ')
			return (0);
		j++;
	}
	return (1);
}

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
	i = -1;
	while (map->map[++i])
	{
		j = 0;
		if (ft_all_space(map, i))
			continue ;
		while (map->map[i][j] == ' ')
			j++;
		if (map->map[i][j] != '1' && map->map[i][j] != 'm')
			return (1);
		map->map[i][j] = 'm';
	}
	return (0);
}

int	ft_verif_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map[i])
		i++;
	i--;
	while (map->map[j] && ft_all_space(map, j))
		j++;
	while (map->map[i] && ft_all_space(map, i))
		i--;
	if (!map->map[j] || !map->map[i])
		return (1);
	if (ft_first_last(map, j) || ft_first_last(map, i))
		return (1);
	if (ft_mid_map(map))
		return (1);
	return (0);
}

t_map	*ft_parsing(int ac, char **av)
{
	int		fd;
	t_map	*map;

	map = malloc(sizeof(t_map) * 1);
	if (!map)
		return (NULL);
	ft_init_map(map);
	map->elem = malloc(sizeof(t_elem) * 1);
	if (!map->elem)
		exit_msg(map, NULL, EXIT_FAILURE, "Memory allocation error.");
	ft_init_elem(map->elem);
	fd = ft_verif_name(ac, av);
	if (ft_parse_elem(fd, map->elem) || ft_verif_elem(map->elem))
	{
		close(fd);
		exit_msg(map, NULL, EXIT_FAILURE, "Memory allocation error.");
	}
	map->map = ft_parse_map(fd, map);
	close(fd);
	if (!map->map)
		exit_msg(map, NULL, EXIT_FAILURE, "Memory allocation error.");
	if (ft_verif_map(map))
		exit_msg(map, NULL, EXIT_FAILURE, "Memory allocation error.");
	return (map);
}

t_game	*init_game(t_map *map)
{
	t_game	*game;

	game = malloc(sizeof(t_game) * 1);
	if (!game)
		exit_msg(map, NULL, EXIT_FAILURE, "Memory allocation error.");
	game->size = 32;
	game->mlx = NULL;
	game->mlx_win = NULL;
	game->map = map;
	return (game);
}
