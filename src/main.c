#include "cub3d.h"

void	ft_free_game_2(t_game *game)
{
	free(game->player->pos);
	free(game->player);
	game->player = NULL;
	destroy_mlx(game->mlx, game->mlx_win, 0);
	destroy_mlx(game->mlx, NULL, 1);
	free(game->mlx);
	free(game->ray);
	game->mlx = NULL;
	free(game);
	game = NULL;
}

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
void	print_elem(t_elem *elem)
{
	printf("east valeur: %s\n", elem->ea);
	printf("north valeur: %s\n", elem->no);
	printf("south valeur: %s\n", elem->so);
	printf("west valeur: %s\n", elem->we);
	print_tab(elem->c, "Plafond");
	print_tab(elem->f, "sol");
}

void	ft_game(t_game *game)
{
	if (game->forward == 1)
		move_up(game);
	if (game->backward == 1)
		move_down(game);
	if (game->left == 1)
		move_left(game);
	if (game->right == 1)
		move_right(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[0]->img, 0, 0);
}

int	main(int ac, char **av)
{
	t_game	*game;

	game = ft_parsing(ac, av);
	init_window(game);
	cub3d(game);
	mlx_hook(game->mlx_win, 2, (1 << 0), do_event, game);
	mlx_hook(game->mlx_win, 3, (1 << 1), stop_event, game);
	mlx_hook(game->mlx_win, 17, (1 << 0), exit_game_v, game);
	mlx_loop_hook(game->mlx, ft_game, game);
	mlx_loop(game->mlx);
	return (0);
}
