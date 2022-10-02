#include "cub3d.h"

char	*ft_joinmap(int fd)
{
	char	*join;
	char	*line;

	join = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		join = ft_strjoin(join, line);
		if (!join)
			return (NULL);
		free(line);
	}
	return (join);
}

char	*ft_verif_join(char *new_j, t_map *map)
{
	char	*j;
	int		i;

	i = 0;
	while (new_j[i] && new_j[i] == '\n')
		i++;
	if (new_j[i] == '\0')
		return (free(new_j), NULL);
	j = ft_strdup_2(new_j + i, '\0');
	free(new_j);
	i = -1;
	while (j[++i])
	{
		if (j[i] != '\n' && j[i] != 'W' && j[i] != 'E' && j[i] != 'S'
			&& j[i] != 'N' && j[i] != '0' && j[i] != '1' && j[i] != ' ')
			return (free(j), NULL);
		if (j[i] == 'S' || j[i] == 'N' || j[i] == 'E' || j[i] == 'W')
		{
			map->player = j[i];
			map->nb_player += 1;
		}
	}
	if (map->nb_player != 1)
		return (free(j), NULL);
	return (j);
}

int	ft_double_nl(char *join)
{
	int	i;
	int	v;

	i = -1;
	v = 0;
	while (join[++i])
	{
		if (join[i] == '\n')
			v += 1;
		else
			v = 0;
		if (v > 1)
			return (1);
	}
	return (0);
}

char	**ft_parse_map(int fd, t_map *map)
{
	char	**tab;
	char	*join;
	char	*new_join;

	join = ft_joinmap(fd);
	if (!join)
		return (NULL);
	new_join = ft_verif_join(join, map);
	if (!new_join)
		return (NULL);
	if (new_join[ft_strlen(new_join) - 1] == '\n' || ft_double_nl(new_join))
		return (free(new_join), NULL);
	tab = ft_split(new_join, '\n');
	free(new_join);
	return (tab);
}
