#include "cub3d.h"

void	destroy_mlx(void *mlx, void *ptr, int mode)
{
	if (!mode && mlx && ptr)
		mlx_destroy_window(mlx, ptr);
	else if (mode == 1 && mlx)
		mlx_destroy_display(mlx);
}
