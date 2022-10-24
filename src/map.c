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

void init_ray2(t_ray *ray, t_game *game)
{
	if (game->player->player == 'S')
	{
		ray->dirx = 0.0;
		ray->diry = 1.0;
		ray->planex = sin(-1);
		ray->planey = 0.0;
	}
	if (game->player->player == 'W')
	{
		ray->dirx = -1.0;
		ray->diry = 0.0;
		ray->planex = 0.0;
		ray->planey = -cos(1);
	}
}

t_ray	*init_ray(t_game *game)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray) * 1);
	if (!ray)
		return (NULL);
	ray->dirx = 0.0;
	ray->diry = -1.0;
	ray->planex = sin(1);
	ray->planey = 0.0;
	if (game->player->player == 'E')
	{
		ray->dirx = 1.0;
		ray->diry = 0.0;
		ray->planex = 0.0;
		ray->planey = 1.0 * cos(1);
	}
	init_ray2(ray, game);
	return (ray);
}

void	cub3d(t_game *game)
{
	int		i;
	double	wallx;
	double camerax;
	double raydirx;
	double raydiry;
	double sidedistx;
	double sidedisty;
	double deltadistx;
	double deltadisty;
	double perpwalldist;
	double texpos;
	double step;
	int	stepx;
	int	stepy;
	int	texX;
	int	hit;
	int side;
	int lineheight;

	i = -1;
	while (++i < L)
	{
		game->ray->mapx = (int)game->player->pos->x;
		game->ray->mapy = (int)game->player->pos->y;
		camerax =  2.0 * (double)i / (double)L - 1.0;
		raydirx = game->ray->dirx + game->ray->planex * camerax;
		raydiry = game->ray->diry + game->ray->planey * camerax;
		deltadistx = fabs(1 / raydirx);
		deltadisty = fabs(1 / raydiry);
		if (raydirx < 0)
		{
			stepx = -1;
			sidedistx = (game->player->pos->x - game->ray->mapx) * deltadistx;
		}
		else
		{
			stepx = 1;
			sidedistx = (game->ray->mapx + 1.0 - game->player->pos->x) * deltadistx;
		}
		if (raydiry < 0)
		{
			stepy = -1;
			sidedisty = (game->player->pos->y - game->ray->mapy) * deltadisty;
		}
		else
		{
			stepy = 1;
			sidedisty = (game->ray->mapy + 1.0 - game->player->pos->y) * deltadisty;
		}
		hit = 0;
		while (hit == 0)
		{
			if (sidedistx < sidedisty)
			{
				sidedistx += deltadistx;
				game->ray->mapx += stepx;
				side = 0;
			}
			else
			{
				sidedisty += deltadisty;
				game->ray->mapy += stepy;
				side = 1;
			}
			if (game->map->map[game->ray->mapy][game->ray->mapx] == '1' || game->map->map[game->ray->mapy][game->ray->mapx] == 'm')
				hit = 1;
		}
		if(side == 0)
		{
			perpwalldist = (sidedistx - deltadistx);
			wallx = game->player->pos->y + perpwalldist * raydiry;
		}
		else
		{
			perpwalldist = (sidedisty - deltadisty);
			wallx = game->player->pos->x; + perpwalldist * raydirx;
		}
		wallx -= floor(wallx);
		texX = (int)(wallx * (double)128);
		if(side == 0 && raydirx > 0)
			texX = 128 - texX - 1;
		if(side == 1 && raydiry < 0)
			texX = 128 - texX - 1;
		lineheight = (int)(H / perpwalldist);
		int drawstart = -lineheight / 2 + H / 2;
		if (drawstart < 0)
			drawstart = 0;
		int drawend = lineheight / 2 + H / 2;
		if (drawend >= H)
			drawend = H;
		step = 1 * 128 / H;
		texpos = (drawstart - H / 2 + lineheight / 2) * step;
		if (i == L / 2)
			printf("posx: %f, posy: %f, start: %d, end: %d, perp: %f, delatx: %f, deltay: %f, mapx: %d, mapy: %d\n", game->player->pos->x, game->player->pos->y, drawstart, drawend, perpwalldist, deltadistx, sidedistx, game->ray->mapx, game->ray->mapy);
		ft_print_img(drawstart, drawend, i, game, texpos, step);
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
