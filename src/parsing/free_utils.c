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
	if (map->elem)
		ft_free_elem(map->elem);
	if (map->map)
		ft_free_tab(map->map);
	free(map);
	return (NULL);
}
