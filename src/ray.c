#include "cub3d.h"

void	draw_ray(t_game *game)
{
	t_pos	pos;

	game->ray.length = 0;
	while (game->map->map[(int)((game->player->pos.y + game->ray.length)
			/ game->size)][(int)(game->player->pos.x / game->size)] != 'm'
		&& game->map->map[(int)((game->player->pos.y + game->ray.length)
			/ game->size)][(int)(game->player->pos.x / game->size)] != '1')
		game->ray.length--;
	pos.x = game->player->pos.x;
	pos.y = game->player->pos.y + game->ray.length;
	draw_line(game, game->player->pos, pos, 0x000000);
}

// void	draw_ray(t_game *game)
// {
// 	int		i;
// 	float	cam_x;

// 	i = -1;
// 	while (++i < columns)
// 	{
// 		cam_x = 2 * i / (float)columns - 1;
// 		game->ray.pos.x = game->player->dir.x + game->plane.x * cam_x;
// 		game->ray.pos.y = game->player->dir.y + game->plane.y * cam_x;
// 	}
// }

void	clear_ray(t_game *game)
{
	int	i;

	i = 0;
	while (game->map->map[(int)((game->player->pos.y + i)
			/ game->size)][(int)(game->player->pos.x / game->size)] != 'm'
		&& game->map->map[(int)((game->player->pos.y + i)
			/ game->size)][(int)(game->player->pos.x / game->size)] != '1')
		mlx_put_pixel(game, game->player->pos.x,
			game->player->pos.y + i--, 0x00ff00);
}
