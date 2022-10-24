#include "cub3d.h"

void	init_renderer(t_game *game)
{
	game->renderer = malloc(sizeof(t_renderer) * 1);
	if (!game->renderer)
		exit_game(game, ERR_MALLOC, -1);
}
