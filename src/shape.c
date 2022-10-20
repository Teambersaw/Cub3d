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

//pixels == game->ray.length;
void	draw_line(t_game *game, t_pos p1, t_pos p2, int color)
{
	int		pixels;
	t_pos	delta;

	delta.x = p2.x - p1.x;
	delta.y = p2.y - p1.y;
	pixels = sqrt((delta.x * delta.x) + (delta.y * delta.y));
	delta.x /= pixels;
	delta.y /= pixels;
	while (pixels)
	{
		mlx_put_pixel(game, p1.x, p1.y, color);
		p1.x += delta.x;
		p1.y += delta.y;
		pixels--;
	}
}
