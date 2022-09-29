#include "cub3d.h"

void ft_perror(char *str, int fd, char *line)
{
    if (line)
        free(line);
    if (fd >= 0)
        close (fd);
    ft_putstr_fd("Error\n", 2);
    ft_putstr_fd(str, 2);
    ft_putstr_fd("\n", 2);
    exit(1);
}

int ft_verif_name(char *name)
{
    int i;

    i = ft_strlen(name);
    if (i == 4 || (i == 5 && name[0] == '.' && name[1] == '.')
        || !ft_strnstr(name + (i - 4), ".cub", 4))
        ft_perror("Invalid name: map shoud be a \"\%.cub\" format.", -1, NULL);
    i = open(name, __O_DIRECTORY);
    if (i > 0)
        ft_perror("Name should not be a directory.", i, NULL);
    i = open(name, O_RDONLY | __O_NOFOLLOW);
    if (i == -1)
        ft_perror("This is not a valid file.", -1, NULL);
    return (i);
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
    printf("east valeur: %s\n", elem.EA);
    printf("north valeur: %s\n", elem.NO);
    printf("south valeur: %s\n", elem.SO);
    printf("west valeur: %s\n", elem.WE);
    print_tab(elem.C, "Plafond");
    print_tab(elem.F, "sol");                
}

int main(int ac, char **av)
{
    t_elem  elem;
    int     fd;

    if (ac != 2)
        ft_perror("The program take only one argument.", 0, NULL);
    fd = ft_verif_name(av[1]);
    elem = ft_init_elem();
    if (ft_parsing(fd, &elem))
    {
        print_elem(elem); //test
        ft_free_elem(elem);
        ft_perror("Invalid map.", fd, NULL);
    }
    print_elem(elem); //test
    ft_free_elem(elem);
    close(fd);
    return (0);
}