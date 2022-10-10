#include "cub3d.h"

void	destroy_mlx(void *mlx, void *ptr, int mode)
{
	if (!mode && mlx && ptr)
		mlx_destroy_window(mlx, ptr);
	else if (mode == 1 && mlx)
		mlx_destroy_display(mlx);
	else if (mode == 2 && mlx && ptr)
	{
		mlx_destroy_image(mlx, ptr);
		mlx = NULL;
		ptr = NULL;
	}
}

void	mlx_put_pixel(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->img->addr + (y * game->img->len + x * (game->img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	exit_game(t_game *game)
{
	ft_free_game(game);
	exit(EXIT_SUCCESS);
	return (1);
}

int	do_event(int keycode, t_game *game)
{
	if (keycode == 65307)
		exit_game(game);
	return (1);
}
