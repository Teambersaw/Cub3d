#include "cub3d.h"

int ft_elem_cmp(char *line)
{
    if (!ft_strncmp(line, "NO", 2))
        return (printf("NO\n"), 0);
    if (!ft_strncmp(line, "EA", 2))
        return (printf("EA\n"), 0);
    if (!ft_strncmp(line, "SO", 2))
        return (printf("SO\n"), 0);
    if (!ft_strncmp(line, "WE", 2))
        return (printf("WE\n"), 0);
    if (!ft_strncmp(line, "F", 1))
        return (printf("F\n"), 0);
    if (!ft_strncmp(line, "C", 1))
        return (printf("C\n"), 0);
    return (1);
}

int ft_parse_line(char *line)
{
    int i;

    i = 0;
    while (line[i] && line[i] == ' ')
        i++;
    if (line[i] == '\0')
        return (1);
    if (line[i] == '\n')
        return (1);
    if (ft_elem_cmp(&line[i]))
        return (1);
    return (0); 
}


int ft_parse_elem(int fd)
{
    char    *line;

    line = get_next_line(fd, 1);
    if (!line)
        return (1);
    while (line != NULL)
    {
        if (line[0] == '\n')
        {
            free(line);
            line = get_next_line(fd, 1);
            continue ;
        }
        if (ft_parse_line(line))
            return (free(line), 1);
        free(line);
        line = get_next_line(fd, 1);
    }
    free(line);
    return (0);
}

int ft_parsing(int fd)
{
    if (ft_parse_elem(fd))
        return (1);
    return (0);
}