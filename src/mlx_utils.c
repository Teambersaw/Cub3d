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

	dst = game->img[0]->addr
		+ (y * game->img[0]->len + x * (game->img[0]->bpp / 8));
	*(unsigned int *)dst = color;
}

int	exit_game_v(t_game *game)
{
	close(game->fd);
	ft_free_game(game, -1);
	exit(EXIT_SUCCESS);
	return (1);
}

int	exit_game(t_game *game, char *error, int var)
{
	if (game)
		close(game->fd);
	ft_free_game(game, var);
	if (error)
		ft_perror(error);
	return (1);
}
