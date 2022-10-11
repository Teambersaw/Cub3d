#include "cub3d.h"

void	move_up(t_game *game)
{
	t_pos	pos;

	pos.x = game->player->x;
	pos.y = game->player->y;
	game->player->y -= game->player->speed;
	if (game->map->map[(int)pos.y][(int)pos.x] == 'm'
		&& game->map->map[(int)game->player->y][(int)game->player->x] == 'm')
		return ;
	display_player(game, game->player->x * game->size, game->player->y * game->size, 0x0000ff);
	display_player(game, pos.x * game->size, game->player->y * game->size + 20, 0x00ff00);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img->img, 0, 0);
}

void	move_down(t_game *game)
{
	t_pos	pos;

	pos.x = game->player->x;
	pos.y = game->player->y;
	game->player->y += game->player->speed;
	if (game->map->map[(int)pos.y][(int)pos.x] == 'm'
		&& game->map->map[(int)game->player->y][(int)game->player->x] == 'm')
		return ;
	display_player(game, game->player->x * game->size, game->player->y * game->size, 0x0000ff);
	display_player(game, pos.x * game->size, game->player->y * game->size - 20, 0x00ff00);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img->img, 0, 0);
}

// In future change this to rotate
void	move_left(t_game *game)
{
	t_pos	pos;

	pos.x = game->player->x;
	pos.y = game->player->y;
	game->player->x -= game->player->speed;
	if (game->map->map[(int)pos.y][(int)pos.x] == 'm'
		&& game->map->map[(int)game->player->y][(int)game->player->x] == 'm')
		return ;
	display_player(game, game->player->x * game->size, game->player->y * game->size, 0x0000ff);
	display_player(game, game->player->x * game->size + 20, pos.y * game->size, 0x00ff00);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img->img, 0, 0);
}

// In future change this to rotate
void	move_right(t_game *game)
{
	t_pos pos;

	pos.x = game->player->x;
	pos.y = game->player->y;
	game->player->x += game->player->speed;
	if (game->map->map[(int)game->player->y][(int)game->player->x] == 'm'
		&& game->map->map[(int)pos.y][(int)pos.x] == 'm')
		return ;
	display_player(game, game->player->x * game->size, game->player->y * game->size, 0x0000ff);
	display_player(game, game->player->x * game->size - 20, pos.y * game->size, 0x00ff00);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img->img, 0, 0);
}
