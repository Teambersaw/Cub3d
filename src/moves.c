#include "cub3d.h"

void	move_up(t_game *game)
{
	t_pos	pos;
	t_pos	dims;

	pos.x = game->player->pos.x;
	pos.y = game->player->pos.y;
	if (game->map->map[(int)(pos.y - game->player->speed)][(int)pos.x] == 'm')
		return ;
	game->player->pos.y -= game->player->speed;
	dims.x = 20;
	if (game->player->pos.x != (int)game->player->pos.x)
		dims.x = 19;
	dims.y = pos.y * game->size - game->player->pos.y * game->size;
	pos.y = (int)(game->player->pos.y * game->size) + 20;
	pos.x *= game->size;
	display_player(game, game->player->pos.x * game->size,
		game->player->pos.y * game->size, 0x0000ff);
	draw_rectangle(game, pos, dims, 0x00ff00);
	draw_ray(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[0]->img, 0, 0);
}

void	move_down(t_game *game)
{
	t_pos	pos;
	t_pos	dims;

	pos.x = game->player->pos.x;
	pos.y = game->player->pos.y;
	if (game->map->map[(int)(pos.y + game->player->speed + 0.15f)]
		[(int)pos.x] == 'm')
		return ;
	game->player->pos.y += game->player->speed;
	dims.x = 20;
	if (game->player->pos.x != (int)game->player->pos.x)
		dims.x = 19;
	dims.y = game->player->pos.y * game->size - pos.y * game->size;
	pos.y = (int)(game->player->pos.y * game->size - dims.y);
	pos.x *= game->size;
	display_player(game, game->player->pos.x * game->size,
		game->player->pos.y * game->size, 0x0000ff);
	draw_rectangle(game, pos, dims, 0x00ff00);
	draw_ray(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[0]->img, 0, 0);
}

// In future change this to rotate
void	move_left(t_game *game)
{
	t_pos	pos;
	t_pos	dims;

	pos.x = game->player->pos.x;
	pos.y = game->player->pos.y;
	if (game->map->map[(int)pos.y][(int)(pos.x - game->player->speed)] == 'm')
		return ;
	game->player->pos.x -= game->player->speed;
	dims.x = pos.x * game->size - game->player->pos.x * game->size;
	dims.y = 20;
	if (game->player->pos.y != (int)game->player->pos.y)
		dims.y = 19;
	pos.x = game->player->pos.x * game->size + 20;
	pos.y *= game->size;
	display_player(game, game->player->pos.x * game->size,
		game->player->pos.y * game->size, 0x0000ff);
	draw_rectangle(game, pos, dims, 0x00ff00);
	draw_ray(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[0]->img, 0, 0);
}

// In future change this to rotate
void	move_right(t_game *game)
{
	t_pos	pos;
	t_pos	dims;

	pos.x = game->player->pos.x;
	pos.y = game->player->pos.y;
	if (game->map->map[(int)pos.y]
		[(int)(pos.x + game->player->speed + 0.15f)] == 'm')
		return ;
	game->player->pos.x += game->player->speed;
	dims.x = game->player->pos.x * game->size - pos.x * game->size;
	dims.y = 20;
	if (game->player->pos.y != (int)game->player->pos.y)
		dims.y = 19;
	pos.x = game->player->pos.x * game->size - dims.x;
	pos.y *= game->size;
	display_player(game, game->player->pos.x * game->size,
		game->player->pos.y * game->size, 0x0000ff);
	draw_rectangle(game, pos, dims, 0x00ff00);
	draw_ray(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[0]->img, 0, 0);
}
