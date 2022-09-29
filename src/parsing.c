#include "cub3d.h"

char    *ft_stor(char *line, char *str)
{
    int i;
    int j;

    i = 0;
    if (!line || line[i] != ' ')
        return (NULL);
    while (line && line[i] == ' ')
        i++;
    if (!line || line[i] == '\0' || line[i] == '\n')
        return (NULL);
    j = i;
    while (line && line[i] && line[i] != '\n')
        i++;
    if (!line || !line[i])
        return (NULL);
    if (str)
        free(str);
    str = ft_strdup(line + j, '\n');
    return (str);
}

char    **ft_stor_tab(char *line, char **tab)
{
    char    *s;
    int     i;

    i = 0;
    if (!line || line[i] != ' ')
        return (NULL);
    while (line && line[i] == ' ')
        i++;
    tab = ft_split(line + i, ',');
    if (!tab)
        return (NULL);
    i = 0;
    while (tab[i])
        i++;
    if (i != 3)
        return (ft_free_tab(tab), NULL);
    i = 0;
    while (line[i] && line[i] != '\n')
        i++;
    if (line[i] == '\0')
         return (ft_free_tab(tab), NULL);
    s = ft_strdup(tab[2], '\n');
    free(tab[2]);
    tab[2] = s;
    return (tab);
}

int ft_elem_cmp(char *line, t_elem *elem)
{
    if (!ft_strncmp(line, "NO", 2))
        elem->NO = ft_stor(line + 2, elem->NO);
    else if (!ft_strncmp(line, "EA", 2))
        elem->EA = ft_stor(line + 2, elem->EA);
    else if (!ft_strncmp(line, "SO", 2))
        elem->SO = ft_stor(line + 2, elem->SO);
    else if (!ft_strncmp(line, "WE", 2))
        elem->WE = ft_stor(line + 2, elem->WE);
    else if (!ft_strncmp(line, "F", 1))
        elem->F = ft_stor_tab(line + 1, elem->F);
    else if (!ft_strncmp(line, "C", 1))
        elem->C = ft_stor_tab(line + 1, elem->C);
    else
        return (1);
    elem->index += 1;
    return (0);
}

int ft_parse_line(char *line, t_elem *elem)
{
    int i;

    i = 0;
    while (line[i] && line[i] == ' ')
        i++;
    if (line[i] == '\0')
        return (1);
    if (line[i] == '\n')
        return (1);
    if (ft_elem_cmp(&line[i], elem))
        return (1);
    return (0); 
}

int ft_parse_elem(int fd, t_elem *elem)
{
    char    *line;

    line = get_next_line(fd);
    if (!line)
        return (1);
    while (line != NULL)
    {
        if (line[0] == '\n')
        {
            free(line);
            line = get_next_line(fd);
            continue ;
        }
        if (ft_parse_line(line, elem))
            return (free(line), 1);
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    return (0);
}

int ft_parsing(int fd, t_elem *elem)
{
    if (ft_parse_elem(fd, elem) || ft_verif_elem(elem))
        return (1);
    return (0);
}