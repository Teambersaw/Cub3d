#include "cub3d.h"

int	do_event(int keycode, t_game *game)
{
	if (keycode == 65307)
		exit_game_v(game);
	else if (keycode == 'w' || keycode == 'W' || keycode == 65362)
		move_up(game);
	else if (keycode == 's' || keycode == 'S' || keycode == 65364)
		move_down(game);
	else if (keycode == 'a' || keycode == 'A' || keycode == 65361)
		move_left(game);
	else if (keycode == 'd' || keycode == 'D' || keycode == 65363)
		move_right(game);
	return (1);
}
