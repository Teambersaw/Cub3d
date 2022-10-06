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

t_game	*ft_parsing(int ac, char **av)
{
	int		fd;
	t_game	*game;

	fd = ft_verif_name(ac, av);
	game = ft_init_game();
	ft_init_map(game);
	if (ft_parse_elem(fd, &game->map->elem) || ft_verif_elem(&game->map->elem))
	{
		ft_free_map(game->map);
		return (close(fd), NULL);
	}
	game->map->map = ft_parse_map(fd, &game->map);
	if (!game->map->map || ft_verif_elem(&game->map))
	{
		ft_free_map(game->map);
		return (close(fd), NULL);
	}
	close(fd);
	return (game);
}
