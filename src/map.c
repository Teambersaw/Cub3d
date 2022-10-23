#include "cub3d.h"

int ft_color2(int r, int g, int b)
{
   return (r << 16) + (g << 8) + b;
}


void ft_print_img(int start, int end, int camera, t_game *game, double texpos, double step)
{
	int	i;

	i = 0;
	while (i < H)
	{
		if (i < start && i < end)
			mlx_put_pixel(game, camera, i, game->map->elem->ccolor);
		else if (i > start && i > end)
			mlx_put_pixel(game, camera, i, game->map->elem->fcolor);
		else
			mlx_put_pixel(game, camera, i, ft_color2(game->img[1]->addr[0], game->img[1]->addr[1], game->img[1]->addr[2]));
		i++;
	}
}

t_ray	*init_ray(t_game *game)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray) * 1);
	if (!ray)
		return (NULL);
	ray->dirX = 0.0;
	ray->dirY = -1.0;
	ray->planeX = -0.66;
	ray->planeY = 0.0;
	if (game->player->player == 'E')
	{
		ray->dirX = 1.0;
		ray->dirY = 0.0;
		ray->planeX = 0.0;
		ray->planeY = -0.66;
	}
	if (game->player->player == 'S')
	{
		ray->dirX = 0.0;
		ray->dirY = 1.0;
		ray->planeX = 0.66;
		ray->planeY = 0.0;
	}
	if (game->player->player == 'W')
	{
		ray->dirX = -1.0;
		ray->dirY = 0.0;
		ray->planeX = 0.0;
		ray->planeY = 0.66;
	}
	return (ray);
}

void	cub3d(t_game *game)
{
	int		i;
	double	wallX;
	double cameraX;
	double raydirX;
	double raydirY;
	double sideDistX;
	double sideDistY;
	double deltaDistX;
	double deltaDistY;
	double perpWallDist;
	double texpos;
	double step;
	int	stepX;
	int	stepY;
	int	texX;
	int	hit;
	int side;
	int lineHeight;

	i = -1;
	while (++i < L)
	{
		printf("%f, %f\n", game->player->pos->x, game->player->pos->y);
		game->ray->mapX = (int)game->player->pos->x;
		game->ray->mapY = (int)game->player->pos->y;
		cameraX =  2.0 * (double)i / (double)L - 1.0;
		raydirX = game->ray->dirX + game->ray->planeX * cameraX;
		raydirY = game->ray->dirY + game->ray->planeY * cameraX;
		deltaDistX = fabs(1 / raydirX);
		deltaDistY = fabs(1 / raydirY);
		if (raydirX < 0)
		{
			stepX = -1;
			sideDistX = (game->player->pos->x - game->ray->mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (game->ray->mapX + 1.0 - game->player->pos->x) * deltaDistX;
		}
		if (raydirY < 0)
		{
			stepY = -1;
			sideDistY = (game->player->pos->y - game->ray->mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (game->ray->mapY + 1.0 - game->player->pos->y) * deltaDistY;
		}
		hit = 0;
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				game->ray->mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				game->ray->mapY += stepY;
				side = 1;
			}
			if (game->map->map[game->ray->mapY][game->ray->mapX] == '1' || game->map->map[game->ray->mapY][game->ray->mapX] == 'm')
				hit = 1;
		}
		if(side == 0)
		{
			perpWallDist = (sideDistX - deltaDistX);
			wallX = game->player->pos->y + perpWallDist * raydirY;
		}
		else
		{
			perpWallDist = (sideDistY - deltaDistY);
			wallX = game->player->pos->x; + perpWallDist * raydirX;
		}
		if (i == L / 2)
			printf("%f\n", perpWallDist);
		wallX -= floor(wallX);
		texX = (int)(wallX * (double)128);
		if(side == 0 && raydirX > 0)
			texX = 128 - texX - 1;
		if(side == 1 && raydirY < 0)
			texX = 128 - texX - 1;
		lineHeight = (int)(H / perpWallDist);
		int drawStart = -lineHeight / 2 + H / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + H / 2;
		if (drawEnd >= H)
			drawEnd = H;
		step = 1 * 128 / H;
		texpos = (drawStart - H / 2 + lineHeight / 2) * step;
		if (i == L / 2)
			printf("posx: %f, posy: %f, start: %d, end: %d, perp: %f, delatx: %f, deltay: %f, mapX: %d, mapY: %d\n", game->player->pos->x, game->player->pos->y, drawStart, drawEnd, perpWallDist, deltaDistX, sideDistX, game->ray->mapX, game->ray->mapY);
		ft_print_img(drawStart, drawEnd, i, game, texpos, step);
	}
}

void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_game(game, ERR_MLX, -1);
	ft_create_img(game);
	game->mlx_win = mlx_new_window(game->mlx, L, H, "Cub3D");
	if (!game->mlx_win)
		exit_game(game, ERR_WIN, -1);
	game->ray = init_ray(game);
	if (!game->ray)
		exit_game(game, ERR_MALLOC, -1);
	game->backward = 0;
	game->forward = 0;
	game->left = 0;
	game->right = 0;
}
