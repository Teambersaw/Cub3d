#include "cub3d.h"

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
        ft_free_elem(elem);
        ft_perror("Invalid map.", fd, NULL);
    }
    ft_free_elem(elem);
    close(fd);
    return (0);
}