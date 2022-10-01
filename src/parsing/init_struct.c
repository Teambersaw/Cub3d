#include "cub3d.h"

char	*ft_strdup_2(char *src, char c)
{
	int		i;
	char	*string;

	i = 0;
    if (!src)
        return (NULL);
    if (!c)
		c = '\0';
	while(src[i] && src[i] != c)
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

int ft_atoi_3(const char *nptr, int nb, int minus)
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

void	ft_free_tab(char **tab)
{
    int	i;

    i = -1;
    while (tab && tab[++i])
        free(tab[i]);
    if (tab)
	    free(tab);
}

void    ft_free_elem(t_elem elem)
{
    free(elem.SO);
    free(elem.NO);
    free(elem.WE);
    free(elem.EA);
    ft_free_tab(elem.F);
    ft_free_tab(elem.C);
}

int ft_asign_rgb(t_elem *elem)
{
    elem->FR = ft_atoi_2(elem->F[0]); 
    elem->FG = ft_atoi_2(elem->F[1]);
    elem->FB = ft_atoi_2(elem->F[2]);
    elem->CR = ft_atoi_2(elem->C[0]);
    elem->CG = ft_atoi_2(elem->C[1]);
    elem->CB = ft_atoi_2(elem->C[2]);
    if ((elem->FR < 0 || elem->FR > 255) || (elem->FG < 0 || elem->FG > 255)
        || (elem->FB < 0 || elem->FB > 255) || (elem->CR < 0 || elem->CR > 255)
            || (elem->CG < 0 || elem->CG > 255)
                || (elem->CB < 0 || elem->CB > 255))
        return (1);
    return (0);
}

int ft_verif_elem(t_elem *elem)
{
    int i;

    i = 0;
    if (!elem->NO || !elem->SO || !elem->EA || !elem->WE || !elem->C
        || !elem->F)
        return (1);
    if (elem->C[0] == NULL || elem->C[1] == NULL || elem->C[2] == NULL
        || elem->F[0] == NULL || elem->F[1] == NULL
        || elem->F[1] == NULL || elem->F[2] == NULL)
        return (1);
    while (elem->C[i] && elem->F[i])
    {
        if (ft_asign_rgb(elem))
            return (1);
        i++;
    }
    return (0);
}

t_map   ft_init_map()
{
    t_map   map;

    map.map = NULL;
    map.x = 0;
    map.y = 0;
    map.player = 0;
    map.nb_player = 0;
    return (map);
}

t_elem   ft_init_elem()
{
    t_elem  elem;

    elem.NO = NULL;
    elem.SO = NULL;
    elem.WE = NULL;
    elem.EA = NULL;
    elem.F = NULL;
    elem.C = NULL;
    elem.nb_elem = 0;
    elem.FR = 0; 
    elem.FG = 0;
    elem.FB = 0;
    elem.CR = 0; 
    elem.CG = 0;
    elem.CB = 0;
    return (elem);
}