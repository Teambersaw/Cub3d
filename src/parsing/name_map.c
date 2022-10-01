#include "cub3d.h"

void ft_perror(char *str, int fd, char *line, t_map *map)
{
    if (map != NULL)
        ft_free_map(*map);
    if (line)
        free(line);
    if (fd >= 0)
        close (fd);
    ft_putstr_fd("Error\n", 2);
    ft_putstr_fd(str, 2);
    ft_putstr_fd("\n", 2);
    exit(1);
}

int ft_verif_name(int ac, char **av)
{
    int     i;
    char    *name;

    if (ac != 2)
        ft_perror("The program take only one argument.", 0, NULL, NULL);
    name = av[1];
    i = ft_strlen(name);
    if (i == 4 || (i == 5 && name[0] == '.' && name[1] == '.')
        || !ft_strnstr(name + (i - 4), ".cub", 4))
        ft_perror("Invalid name: map shoud be a \"\%.cub\" format.",
            -1, NULL, NULL);
    i = open(name, __O_DIRECTORY);
    if (i > 0)
        ft_perror("Name should not be a directory.", i, NULL, NULL);
    i = open(name, O_RDONLY | __O_NOFOLLOW);
    if (i == -1)
        ft_perror("This is not a valid file.", -1, NULL, NULL);
    return (i);
}
