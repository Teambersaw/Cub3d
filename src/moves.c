#include "cub3d.h"

//In future need to check collision with the length of the ray
void	move_up(t_game *game)
{
	t_pos	pos;

	pos.x = game->player->pos->x;
	pos.y = game->player->pos->y;
	if (game->map->map[(int)(pos.y - game->player->speed)][(int)pos.x] == 'm'
		|| game->map->map[(int)(pos.y - game->player->speed)]
		[(int)pos.x] == '1')
		return ;
	game->player->pos->y -= game->player->speed;
	display_player(game, game->player->pos->x * game->size,
		game->player->pos->y * game->size, 0x0000ff);
	// display_player(game, pos.x * game->size, game->player->pos->y * game->size + 20, 0x00ff00);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img->img, 0, 0);
}

void	move_down(t_game *game)
{
	t_pos	pos;

	pos.x = game->player->pos->x;
	pos.y = game->player->pos->y;
	if (game->map->map[(int)(pos.y + (game->player->speed * 3))][(int)pos.x]
		== 'm' || game->map->map[(int)(pos.y + (game->player->speed * 3))]
			[(int)pos.x] == '1')
		return ;
	game->player->pos->y += game->player->speed;
	display_player(game, game->player->pos->x * game->size,
		game->player->pos->y * game->size, 0x0000ff);
	// display_player(game, pos.x * game->size, game->player->pos->y * game->size - 20, 0x00ff00);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img->img, 0, 0);
}

// In future change this to rotate
void	move_left(t_game *game)
{
	t_pos	pos;

	pos.x = game->player->pos->x;
	pos.y = game->player->pos->y;
	if (game->map->map[(int)(pos.y)][(int)(pos.x - game->player->speed)] == 'm'
		|| game->map->map[(int)(pos.y)]
		[(int)(pos.x - game->player->speed)] == '1')
		return ;
	game->player->pos->x -= game->player->speed;
	display_player(game, game->player->pos->x * game->size,
		game->player->pos->y * game->size, 0x0000ff);
	// display_player(game, game->player->pos->x * game->size + 20, pos.y * game->size, 0x00ff00);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img->img, 0, 0);
}

// In future change this to rotate
void	move_right(t_game *game)
{
	t_pos	pos;

	pos.x = game->player->pos->x;
	pos.y = game->player->pos->y;
	if (game->map->map[(int)(pos.y)][(int)(pos.x + (game->player->speed * 3))]
		== 'm' || game->map->map[(int)(pos.y)]
			[(int)(pos.x + (game->player->speed * 3))] == '1')
		return ;
	game->player->pos->x += game->player->speed;
	display_player(game, game->player->pos->x * game->size,
		game->player->pos->y * game->size, 0x0000ff);
	// display_player(game, game->player->pos->x * game->size - 20, pos.y * game->size, 0x00ff00);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img->img, 0, 0);
}
