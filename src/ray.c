#include "cub3d.h"

void	draw_ray(t_game *game)
{
	game->ray.length = 0;
	while (game->map->map[(int)((game->player->pos->y + game->ray.length)
			/ game->size)][(int)(game->player->pos->x / game->size)] != 'm')
	{
		mlx_put_pixel(game, game->player->pos->x,
			game->player->pos->y + game->ray.length, 0x000000);
		game->ray.length--;
	}
	game->ray.length = abs(game->ray.length);
}

void	clear_ray(t_game *game)
{
	int	i;

	i = 0;
	while (game->map->map[(int)((game->player->pos->y + i)
			/ game->size)][(int)(game->player->pos->x / game->size)] != 'm')
		mlx_put_pixel(game, game->player->pos->x,
			game->player->pos->y + i--, 0x00ff00);
}
