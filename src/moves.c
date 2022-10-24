#include "cub3d.h"

void	move_forward(t_game *game)
{
	if (game->map->map[(int)(game->player->pos->y + game->ray->diry
			* MOVE_SPEED)][(int)(game->player->pos->x)] != 'm')
		game->player->pos->y += game->ray->diry * MOVE_SPEED;
	if (game->map->map[(int)(game->player->pos->y)]
		[(int)(game->player->pos->x + game->ray->dirx * MOVE_SPEED)] != 'm')
		game->player->pos->x += game->ray->dirx * MOVE_SPEED;
	cub3d(game);
}

void	move_backward(t_game *game)
{
	if (game->map->map[(int)(game->player->pos->y - game->ray->diry
			* MOVE_SPEED)][(int)(game->player->pos->x)] != 'm')
		game->player->pos->y -= game->ray->diry * MOVE_SPEED;
	if (game->map->map[(int)(game->player->pos->y)]
		[(int)(game->player->pos->x - game->ray->dirx * MOVE_SPEED)] != 'm')
		game->player->pos->x -= game->ray->dirx * MOVE_SPEED;
	cub3d(game);
}

void	turn_right(t_game *game)
{
	double	olddirx;
	double	oldplanex;

	olddirx = game->ray->dirx;
	game->ray->dirx = game->ray->dirx * cos(ROT_SPEED)
		- game->ray->diry * sin(ROT_SPEED);
	game->ray->diry = olddirx * sin(ROT_SPEED)
		+ game->ray->diry * cos(ROT_SPEED);
	oldplanex = game->ray->planex;
	game->ray->planex = game->ray->planex * cos(ROT_SPEED)
		- game->ray->planey * sin(ROT_SPEED);
	game->ray->planey = oldplanex * sin(ROT_SPEED)
		+ game->ray->planey * cos(ROT_SPEED);
	cub3d(game);
}

void	turn_left(t_game *game)
{
	double	olddirx;
	double	oldplanex;

	olddirx = game->ray->dirx;
	game->ray->dirx = game->ray->dirx * cos(-ROT_SPEED)
		- game->ray->diry * sin(-ROT_SPEED);
	game->ray->diry = olddirx * sin(-ROT_SPEED)
		+ game->ray->diry * cos(-ROT_SPEED);
	oldplanex = game->ray->planex;
	game->ray->planex = game->ray->planex * cos(-ROT_SPEED)
		- game->ray->planey * sin(-ROT_SPEED);
	game->ray->planey = oldplanex * sin(-ROT_SPEED)
		+ game->ray->planey * cos(-ROT_SPEED);
	cub3d(game);
}
