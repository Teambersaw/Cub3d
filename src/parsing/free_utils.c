#include "cub3d.h"

void	*ft_free_elem(t_elem *elem)
{
	if (elem->so)
		free(elem->so);
	if (elem->no)
		free(elem->no);
	if (elem->we)
		free(elem->we);
	if (elem->ea)
		free(elem->ea);
	if (elem->f)
		ft_free_tab(elem->f);
	if (elem->c)
		ft_free_tab(elem->c);
	free(elem);
	elem = NULL;
	return (NULL);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab && tab[++i])
		free(tab[i]);
	if (tab)
		free(tab);
	tab = NULL;
}

void	*ft_free_map(t_map *map)
{
	if (!map)
		return (NULL);
	if (map->elem)
		ft_free_elem(map->elem);
	if (map->map)
		ft_free_tab(map->map);
	free(map);
	map = NULL;
	return (NULL);
}

void	*ft_free_game(t_game *game)
{
	if (!game)
		return (NULL);
	if (game->map)
		ft_free_map(game->map);
	destroy_mlx(game->mlx, game->mlx_win, 0);
	destroy_mlx(game->mlx, NULL, 1);
	free(game->mlx);
	game->mlx = NULL;
	free(game);
	game = NULL;
	return (NULL);
}

void	exit_msg(t_map *map, t_game *game, int exit_code, char *msg)
{
	if (exit_code && msg)
		ft_putendl_fd(msg, STDERR_FILENO);
	else if (msg)
		ft_putendl_fd(msg, STDOUT_FILENO);
	ft_free_game(game);
	ft_free_map(map);
	exit(exit_code);
}
