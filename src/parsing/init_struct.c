#include "cub3d.h"

t_elem	*ft_init_elem(void)
{
	t_elem	*elem;

	elem = malloc(sizeof(t_elem) * 1);
	if (!elem)
		return (NULL);
	elem->no = NULL;
	elem->so = NULL;
	elem->we = NULL;
	elem->ea = NULL;
	elem->f = NULL;
	elem->c = NULL;
	elem->nb_elem = 0;
	elem->fr = 0;
	elem->fg = 0;
	elem->fb = 0;
	elem->cr = 0;
	elem->cg = 0;
	elem->cb = 0;
	elem->fcolor = 0;
	elem->ccolor = 0;
	return (elem);
}

t_map	*ft_init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map) * 1);
	if (!map)
		return (NULL);
	map->map = NULL;
	map->nb_player = 0;
	map->elem = ft_init_elem();
	if (!map->elem)
	{
		free(map);
		return (NULL);
	}
	return (map);
}

t_img	*init_img(void)
{
	t_img	*img;

	img = malloc(sizeof(t_img) * 1);
	if (!img)
		return (NULL);
	img->img = NULL;
	img->addr = NULL;
	return (img);
}

t_player	*init_player(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player) * 1);
	if (!player)
		return (NULL);
	player->speed = 0.1f;
	player->player = 0;
	player->pos.x = 0;
	player->pos.y = 0;
	player->dir.x = -1;
	player->dir.y = 0;
	return (player);
}
