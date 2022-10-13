#include "cub3d.h"

void	draw_rectangle(t_game *game, t_pos pos, t_pos dims, int color)
{
	int	i;
	int	j;

	i = pos.y;
	while (i < pos.y + dims.y)
	{
		j = pos.x;
		while (j < pos.x + dims.x)
		{
			mlx_put_pixel(game, j, i, color);
			j++;
		}
		i++;
	}
}

