#include "cub3d.h"

void	move_up(t_game *game)
{
	if (game->map->map[(int)(game->player->pos->y + game->ray->dirY * moveSpeed)][(int)(game->player->pos->x)] != 'm')
		game->player->pos->x += game->ray->dirX * moveSpeed;
	if (game->map->map[(int)(game->player->pos->y)][(int)(game->player->pos->x + game->ray->dirX * moveSpeed)] != 'm')
		game->player->pos->y += game->ray->dirY * moveSpeed;
	cub3d(game);
}

void	move_down(t_game *game)
{
	if (game->map->map[(int)(game->player->pos->y - game->ray->dirY * moveSpeed)][(int)(game->player->pos->x)] != 'm')
		game->player->pos->x -= game->ray->dirX * moveSpeed;
	if (game->map->map[(int)(game->player->pos->y)][(int)(game->player->pos->x - game->ray->dirX * moveSpeed)] != 'm')
		game->player->pos->y -= game->ray->dirY * moveSpeed;
	cub3d(game);
}

void	move_right(t_game *game)
{
	double oldDirX;
	double oldPlaneX;

	oldDirX = game->ray->dirX;
	game->ray->dirX = game->ray->dirX * cos(-rotSpeed) - game->ray->dirY * sin(-rotSpeed);
	game->ray->dirY = oldDirX * sin(-rotSpeed) + game->ray->dirY * cos(-rotSpeed);
	oldPlaneX = game->ray->planeX;
	game->ray->planeX = game->ray->planeX * cos(-rotSpeed) - game->ray->planeY * sin(-rotSpeed);
	game->ray->planeY = oldPlaneX * sin(-rotSpeed) + game->ray->planeY * cos(-rotSpeed);
	cub3d(game);
}

void	move_left(t_game *game)
{
	double oldDirX;
	double oldPlaneX;

	oldDirX = game->ray->dirX;
	game->ray->dirX = game->ray->dirX * cos(rotSpeed) - game->ray->dirY * sin(rotSpeed);
	game->ray->dirY = oldDirX * sin(rotSpeed) + game->ray->dirY * cos(rotSpeed);
	oldPlaneX = game->ray->planeX;
	game->ray->planeX = game->ray->planeX * cos(rotSpeed) - game->ray->planeY * sin(rotSpeed);
	game->ray->planeY = oldPlaneX * sin(rotSpeed) + game->ray->planeY * cos(rotSpeed);
	cub3d(game);
}
