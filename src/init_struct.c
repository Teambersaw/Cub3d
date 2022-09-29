#include "cub3d.h"

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

t_elem   ft_init_elem()
{
    t_elem  elem;

    elem.NO = NULL;
    elem.SO = NULL;
    elem.WE = NULL;
    elem.EA = NULL;
    elem.F = NULL;
    elem.C = NULL;
    elem.index = 0;
    elem.FR = 0; 
    elem.FG = 0;
    elem.FB = 0;
    elem.CR = 0; 
    elem.CG = 0;
    elem.CB = 0;
    return (elem);
}