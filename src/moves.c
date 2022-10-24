#include "cub3d.h"

void	move_up(t_game *game)
{
	if (game->map->map[(int)(game->player->pos->y + game->ray->diry * moveSpeed)][(int)(game->player->pos->x)] != 'm')
		game->player->pos->x += game->ray->dirx * moveSpeed;
	if (game->map->map[(int)(game->player->pos->y)][(int)(game->player->pos->x + game->ray->dirx * moveSpeed)] != 'm')
		game->player->pos->y += game->ray->diry * moveSpeed;
	cub3d(game);
}

void	move_down(t_game *game)
{
	if (game->map->map[(int)(game->player->pos->y - game->ray->diry * moveSpeed)][(int)(game->player->pos->x)] != 'm')
		game->player->pos->x -= game->ray->dirx * moveSpeed;
	if (game->map->map[(int)(game->player->pos->y)][(int)(game->player->pos->x - game->ray->dirx * moveSpeed)] != 'm')
		game->player->pos->y -= game->ray->diry * moveSpeed;
	cub3d(game);
}

void	move_right(t_game *game)
{
	double	olddirx;
	double	oldplanex;

	olddirx = game->ray->dirx;
	game->ray->dirx = game->ray->dirx * cos(rotSpeed) - game->ray->diry * sin(rotSpeed);
	game->ray->diry = olddirx * sin(rotSpeed) + game->ray->diry * cos(rotSpeed);
	oldplanex = game->ray->planex;
	game->ray->planex = game->ray->planex * cos(rotSpeed) - game->ray->planey * sin(rotSpeed);
	game->ray->planey = oldplanex * sin(rotSpeed) + game->ray->planey * cos(rotSpeed);
	cub3d(game);
}

void	move_left(t_game *game)
{
	double	olddirx;
	double	oldplanex;

	olddirx = game->ray->dirx;
	game->ray->dirx = game->ray->dirx * cos(-rotSpeed) - game->ray->diry * sin(-rotSpeed);
	game->ray->diry = olddirx * sin(-rotSpeed) + game->ray->diry * cos(-rotSpeed);
	oldplanex = game->ray->planex;
	game->ray->planex = game->ray->planex * cos(-rotSpeed) - game->ray->planey * sin(-rotSpeed);
	game->ray->planey = oldplanex * sin(-rotSpeed) + game->ray->planey * cos(-rotSpeed);
	cub3d(game);
}
