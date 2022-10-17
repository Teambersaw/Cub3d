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

void	draw_line(t_game *game, t_pos p1, t_pos p2, int color)
{
	t_pos	tmp;

	tmp.y = p1.y;
	tmp.x = p1.x;
	while (tmp.y != p2.y)
	{
		mlx_put_pixel(game, tmp.x++, tmp.y, color);
		tmp.y += get_func(tmp, p2);
	}
}
