#include "cub3d.h"

int	ft_asign_rgb(t_elem *elem)
{
	elem->fr = ft_atoi_2(elem->f[0]);
	elem->fg = ft_atoi_2(elem->f[1]);
	elem->fb = ft_atoi_2(elem->f[2]);
	elem->cr = ft_atoi_2(elem->c[0]);
	elem->cg = ft_atoi_2(elem->c[1]);
	elem->cb = ft_atoi_2(elem->c[2]);
	if ((elem->fr < 0 || elem->fr > 255) || (elem->fg < 0 || elem->fg > 255)
		|| (elem->fb < 0 || elem->fb > 255) || (elem->cr < 0 || elem->cr > 255)
		|| (elem->cg < 0 || elem->cg > 255)
		|| (elem->cb < 0 || elem->cb > 255))
		return (1);
	return (0);
}

int	ft_verif_elem(t_elem *elem)
{
	int	i;

	i = 0;
	if (!elem->no || !elem->so || !elem->ea || !elem->we || !elem->c
		|| !elem->f)
		return (1);
	if (elem->c[0] == NULL || elem->c[1] == NULL || elem->c[2] == NULL
		|| elem->f[0] == NULL || elem->f[1] == NULL
		|| elem->f[1] == NULL || elem->f[2] == NULL)
		return (1);
	while (elem->c[i] && elem->f[i])
	{
		if (ft_asign_rgb(elem))
			return (1);
		i++;
	}
	return (0);
}

void	ft_init_map(t_game *game)
{
	game->map = malloc(sizeof(t_map) * 1);
	if (!game->map)
	{
		free(game);
		ft_putendl_fd("Memory allocation error.", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	game->map->map = NULL;
	game->map->x = 0;
	game->map->y = 0;
	game->map->player = 0;
	game->map->nb_player = 0;
	game->map->elem = ft_init_elem();
}

t_elem	ft_init_elem(void)
{
	t_elem	elem;

	elem.no = NULL;
	elem.so = NULL;
	elem.we = NULL;
	elem.ea = NULL;
	elem.f = NULL;
	elem.c = NULL;
	elem.nb_elem = 0;
	elem.fr = 0;
	elem.fg = 0;
	elem.fb = 0;
	elem.cr = 0;
	elem.cg = 0;
	elem.cb = 0;
	return (elem);
}

t_game	*ft_init_game(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game) * 1);
	if (!game)
	{
		ft_putendl_fd("Memory allocation error", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	game->mlx = NULL;
	game->mlx_win = NULL;
	game->map = NULL;
	return (game);
}
