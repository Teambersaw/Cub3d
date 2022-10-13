#include "cub3d.h"

//In future need to check collision with the length of the ray
void	move_up(t_game *game)
{
	t_pos	pos;
	t_pos	dims;

	pos.x = game->player->pos->x;
	pos.y = game->player->pos->y;
	if (game->map->map[(int)(pos.y - game->player->speed)][(int)pos.x] == 'm')
		return ;
	game->player->pos->y -= game->player->speed;
	dims.x = 20;
	dims.y = (int)((pos.y * game->size) - (game->player->pos->y * game->size));
	pos.y = (int)(game->player->pos->y * game->size + 20);
	pos.x *= game->size;
	display_player(game, game->player->pos->x * game->size,
		game->player->pos->y * game->size, 0x0000ff);
	draw_rectangle(game, pos, dims, 0x00ff00);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img->img, 0, 0);
}

void	move_down(t_game *game)
{
	t_pos	pos;
	t_pos	dims;

	pos.x = game->player->pos->x;
	pos.y = game->player->pos->y;
	if (game->map->map[(int)(pos.y + (game->player->speed * 3))][(int)pos.x]
		== 'm')
		return ;
	game->player->pos->y += game->player->speed;
	dims.x = 20;
	dims.y = (int)((game->player->pos->y * game->size) - (pos.y * game->size));
	pos.x *= game->size;
	pos.y = (int)(game->player->pos->y * game->size - dims.y);
	display_player(game, game->player->pos->x * game->size,
		game->player->pos->y * game->size, 0x0000ff);
	draw_rectangle(game, pos, dims, 0x00ff00);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img->img, 0, 0);
}

// In future change this to rotate
void	move_left(t_game *game)
{
	t_pos	pos;
	t_pos	dims;

	pos.x = game->player->pos->x;
	pos.y = game->player->pos->y;
	if (game->map->map[(int)(pos.y)][(int)(pos.x - game->player->speed)] == 'm')
		return ;
	game->player->pos->x -= game->player->speed;
	dims.x = (int)((pos.x * game->size) - (game->player->pos->x * game->size) + 1);
	dims.y = 20;
	pos.x = (int)(game->player->pos->x * game->size) + 20;
	pos.y *= game->size;
	display_player(game, game->player->pos->x * game->size,
		game->player->pos->y * game->size, 0x0000ff);
	draw_rectangle(game, pos, dims, 0x00ff00);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img->img, 0, 0);
}

// In future change this to rotate
void	move_right(t_game *game)
{
	t_pos	pos;
	t_pos	dims;

	pos.x = game->player->pos->x;
	pos.y = game->player->pos->y;
	if (game->map->map[(int)(pos.y)][(int)(pos.x + (game->player->speed * 3))]
		== 'm')
		return ;
	game->player->pos->x += game->player->speed;
	dims.x = (int)((game->player->pos->x * game->size) - (pos.x * game->size) + 1);
	dims.y = 20;
	pos.x = (int)(game->player->pos->x * game->size - dims.x);
	pos.y *= game->size;
	display_player(game, game->player->pos->x * game->size,
		game->player->pos->y * game->size, 0x0000ff);
	draw_rectangle(game, pos, dims, 0x00ff00);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img->img, 0, 0);
}
