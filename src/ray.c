#include "cub3d.h"

void	draw_ray(t_game *game)
{
	game->ray.length = 0;
	while (game->map->map[(int)((game->player->pos->y + game->ray.length)
			/ game->size)][(int)(game->player->pos->x / game->size)] != 'm')
	{
		mlx_put_pixel(game, game->player->pos->x, game->player->pos->y + game->ray.length, 0x000000);
		game->ray.length--;
	}
	printf("%d\n", abs(game->ray.length));
}
