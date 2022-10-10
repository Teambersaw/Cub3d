#include "cub3d.h"

void	display_square(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = y;
	while (i < y + game->size)
	{
		j = x;
		while (j < x + game->size)
			mlx_put_pixel(game, j++, i, color);
		i++;
	}
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
				color = 0xFF0000;
			else if (game->map->map[i][j] == '0')
				color = 0x00FF00;
			else if (game->map->map[i][j] == 'N')
				color = 0x0000FF;
			display_square(game, j * game->size, i * game->size, color);
		}
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img->img, 0, 0);
}

void	init_window(t_game *game)
{
	int		width;
	int		height;

	width = ft_strlen(game->map->map[0]);
	height = tablen(game->map->map);
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, width * game->size,
			height * game->size, "Cub3D");
	game->img->img = mlx_new_image(game->mlx, width * game->size,
			height * game->size);
	game->img->addr = mlx_get_data_addr(game->img->img, &game->img->bpp,
			&game->img->len, &game->img->endian);
	display_map(game);
}
