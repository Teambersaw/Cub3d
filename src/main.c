#include "cub3d.h"

//fonction test
void	print_tabb(char **tab)
{
	int	i;

	i = -1;
	if (!tab)
		return ;
	while (tab[++i])
		printf("%s\n", tab[i]);
}

//fonction test
void	print_tab(char **tab, char *car)
{
	int	i;

	i = -1;
	if (!tab)
		return ;
	while (tab[++i])
		printf("%s valeur: %s\n", car, tab[i]);
}

//fonction test
void	print_elem(t_elem elem)
{
	printf("east valeur: %s\n", elem.ea);
	printf("north valeur: %s\n", elem.no);
	printf("south valeur: %s\n", elem.so);
	printf("west valeur: %s\n", elem.we);
	print_tab(elem.c, "Plafond");
	print_tab(elem.f, "sol");
}

int	main(int ac, char **av)
{
	t_map	*map;
	t_game	*game;

	map = ft_parsing(ac, av);
	if (!map)
		ft_perror("invalid map", -1, NULL, map);
	game = init_game(map);
	(void)game;
	ft_putendl_fd("valid map", STDOUT_FILENO);
	ft_free_game(game);
	return (0);
}
