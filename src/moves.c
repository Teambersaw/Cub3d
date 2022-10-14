#include "cub3d.h"

void	move_up(t_game *game)
{
	t_pos	pos;
	t_pos	dims;

	pos.x = game->player->pos->x;
	pos.y = game->player->pos->y;
	if (game->ray.length <= 1)
		return ;
	else if (game->ray.length < game->player->speed)
		game->player->pos->y -= game->ray.length - 1;
	else
		game->player->pos->y -= game->player->speed;
	dims.x = 20;
	dims.y = (int)(pos.y - game->player->pos->y);
	pos.y = (int)(game->player->pos->y) + 20;
	display_player(game, game->player->pos->x, game->player->pos->y, 0x0000ff);
	draw_rectangle(game, pos, dims, 0x00ff00);
	draw_ray(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img->img, 0, 0);
}

void	move_down(t_game *game)
{
	t_pos	pos;
	t_pos	dims;

	pos.x = game->player->pos->x;
	pos.y = game->player->pos->y;
	if (game->map->map[(int)((pos.y + (game->player->speed + 20)) / game->size)]
		[(int)(pos.x / game->size)] == 'm')
		return ;
	game->player->pos->y += game->player->speed;
	dims.x = 20;
	dims.y = (int)(game->player->pos->y - pos.y);
	pos.y = (int)(game->player->pos->y - dims.y);
	display_player(game, game->player->pos->x, game->player->pos->y, 0x0000ff);
	draw_rectangle(game, pos, dims, 0x00ff00);
	draw_ray(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img->img, 0, 0);
}

// In future change this to rotate
void	move_left(t_game *game)
{
	t_pos	pos;
	t_pos	dims;

	clear_ray(game);
	pos.x = game->player->pos->x;
	pos.y = game->player->pos->y;
	if (game->map->map[(int)(pos.y / game->size)]
		[(int)(pos.x - game->player->speed) / game->size] == 'm')
		return ;
	game->player->pos->x -= game->player->speed;
	dims.x = (int)(pos.x - game->player->pos->x);
	dims.y = 20;
	pos.x = (int)(game->player->pos->x) + 20;
	display_player(game, game->player->pos->x, game->player->pos->y, 0x0000ff);
	draw_rectangle(game, pos, dims, 0x00ff00);
	draw_ray(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img->img, 0, 0);
}

// In future change this to rotate
void	move_right(t_game *game)
{
	t_pos	pos;
	t_pos	dims;

	clear_ray(game);
	pos.x = game->player->pos->x;
	pos.y = game->player->pos->y;
	if (game->map->map[(int)(pos.y / game->size)]
		[(int)(pos.x + (game->player->speed + 20)) / game->size] == 'm')
		return ;
	game->player->pos->x += game->player->speed;
	dims.x = (int)(game->player->pos->x - pos.x);
	dims.y = 20;
	pos.x = (int)(game->player->pos->x - dims.x);
	display_player(game, game->player->pos->x, game->player->pos->y, 0x0000ff);
	draw_rectangle(game, pos, dims, 0x00ff00);
	draw_ray(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img->img, 0, 0);
}
