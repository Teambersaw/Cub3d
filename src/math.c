#include "cub3d.h"

int	get_func(t_pos p1, t_pos p2)
{
	int	a;
	int	b;
	int	result;

	if (p2.x == p1.x)
		return (1);
	a = (p2.y - p1.y) / (p2.x - p1.x);
	b = a * p1.x - p1.y;
	result = 0;
	return (result);
}
