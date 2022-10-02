#include "cub3d.h"

void	ft_free_map(t_map map)
{
	if (map.elem.SO)
		free(map.elem.SO);
	if (map.elem.NO)
		free(map.elem.NO);
	if (map.elem.WE)
		free(map.elem.WE);
	if (map.elem.EA)
		free(map.elem.EA);
	if (map.elem.F)
		ft_free_tab(map.elem.F);
	if (map.elem.C)
		ft_free_tab(map.elem.C);
	if (map.map)
		ft_free_tab(map.map);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab && tab[++i])
		free(tab[i]);
	if (tab)
		free(tab);
	tab = NULL;
}

char	*ft_strdup_2(char *src, char c)
{
	int		i;
	char	*string;

	i = 0;
	if (!src)
		return (NULL);
	if (!c)
		c = '\0';
	while (src[i] && src[i] != c)
		i++;
	string = malloc(sizeof(char) * (i + 1));
	if (!string)
		return (0);
	i = -1;
	while (src[++i] != c)
		string[i] = src[i];
	string[i] = '\0';
	return (string);
}

int	ft_atoi_3(const char *nptr, int nb, int minus)
{
	if (*nptr < '0' && *nptr > '9')
		return (-1);
	while (*nptr >= '0' && *nptr <= '9')
	{
		nb = nb * 10 + (*(nptr++) - '0');
		if (nb > 999)
			return (-1);
	}
	while (*nptr)
	{
		if (*nptr != ' ')
			return (-1);
		nptr++;
	}
	return (nb * minus);
}

int	ft_atoi_2(const char *nptr)
{
	int	nb;
	int	minus;

	nb = 0;
	minus = 1;
	while (*nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			minus = -1;
		nptr++;
	}
	return (ft_atoi_3(nptr, nb, minus));
}
