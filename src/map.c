#include "cub3d.h"

void	display_player(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = y;
	while (i < y + 20)
	{
		j = x;
		while (j < x + 20)
			mlx_put_pixel(game, j++, i, color);
		i++;
	}
}

void	display_square(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;
	int	player;

	i = y;
	player = 0;
	if (color == 0x0000ff)
	{
		color = 0x00ff00;
		player = 1;
	}
	while (i < y + game->size)
	{
		j = x;
		while (j < x + game->size)
			mlx_put_pixel(game, j++, i, color);
		i++;
	}
	if (player)
		display_player(game, x, y, 0x0000ff);
}

void	display_map(t_game *game)
{
	int	i;
	int	j;
	int	color;

	i = -1;
	while (game->map->map[++i])
	{
		j = -1;
		while (game->map->map[i][++j])
		{
			if (game->map->map[i][j] == '1' || game->map->map[i][j] == 'm')
				color = 0xff0000;
			else if (game->map->map[i][j] == '0')
				color = 0x00ff00;
			else if (game->map->map[i][j] == 'N')
				color = 0x0000ff;
			display_square(game, j * game->size, i * game->size, color);
		}
	}
}

void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_game(game, ERR_MLX, -1);
	ft_create_img(game);
	game->mlx_win = mlx_new_window(game->mlx, 768, 640, "Cub3D");
	if (!game->mlx_win)
		exit_game(game, ERR_WIN, -1);
	display_map(game);
	draw_ray(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[0]->img, 0, 0);
}
