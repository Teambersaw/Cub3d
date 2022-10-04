#include "cub3d.h"

void    print_tabb(char **tab) //fonction test
{
    int i;

    i = -1;
    if (!tab)
        return ;
    while (tab[++i])
        printf("%s\n", tab[i]);
}

void    print_tab(char **tab, char *car) //fonction test
{
    int i;

    i = -1;
    if (!tab)
        return ;
    while (tab[++i])
        printf("%s valeur: %s\n", car, tab[i]);
}

void    print_elem(t_elem elem) //fonction test
{
    printf("east valeur: %s\n", elem.ea);
    printf("north valeur: %s\n", elem.no);
    printf("south valeur: %s\n", elem.so);
    printf("west valeur: %s\n", elem.we);
    print_tab(elem.c, "Plafond");
    print_tab(elem.f, "sol");                
}

int    main(int ac, char **av)
{
    t_map    map;

    map = ft_parsing(ac, av);
    if (map.value == 0)
		 ft_perror("invalid map", -1, NULL, &map);
	ft_putendl_fd("valid map", STDOUT_FILENO);
    ft_free_map(map);
    return (0);
}