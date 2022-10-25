#include "cub3d.h"

int	do_event(int keycode, t_game *game)
{
	if (keycode == 65307)
		exit_game_v(game);
	else if (keycode == 'w' || keycode == 'W' || keycode == 65362)
		game->forward = 1;
	else if (keycode == 's' || keycode == 'S' || keycode == 65364)
		game->backward = 1;
	else if (keycode == 'a' || keycode == 'A' || keycode == 65361)
		game->left = 1;
	else if (keycode == 'd' || keycode == 'D' || keycode == 65363)
		game->right = 1;
	else if (keycode == 'q' || keycode == 'Q')
		game->t_left = 1;
	else if (keycode == 'e' || keycode == 'E')
		game->t_right = 1;
	return (0);
}

int	stop_event(int keycode, t_game *game)
{
	if (keycode == 65307)
		exit_game_v(game);
	else if (keycode == 'w' || keycode == 'W' || keycode == 65362)
		game->forward = 0;
	else if (keycode == 's' || keycode == 'S' || keycode == 65364)
		game->backward = 0;
	else if (keycode == 'a' || keycode == 'A' || keycode == 65361)
		game->left = 0;
	else if (keycode == 'd' || keycode == 'D' || keycode == 65363)
		game->right = 0;
	else if (keycode == 'q' || keycode == 'Q')
		game->t_left = 0;
	else if (keycode == 'e' || keycode == 'E')
		game->t_right = 0;
	return (0);
}
