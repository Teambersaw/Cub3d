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
	t_game	*game;

	game = ft_parsing(ac, av);
	if (!game)
		ft_perror("invalid map", -1, NULL, game->map);
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, 1920, 1080, "Cub3D");
	mlx_hook(game->mlx_win, 2, (1 << 0), quit, game);
	mlx_loop(game->mlx);
	quit(game);
	return (0);
}
