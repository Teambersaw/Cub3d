#include "cub3d.h"

int	main(int ac, char **av)
{
	t_map	map;

	map = ft_parsing(ac, av);
	if (map.value == 0)
		ft_perror("invalid map", -1, NULL, &map);
	ft_free_map(map);
	return (0);
}
