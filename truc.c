#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int ft_storage_xpm(char *line, char *str)
{
    if (str != NULL)
        return (printf("pas bon\n"), 1);
    memcpy(str, line + j, i - j);
}

int ft_elem_cmp(char *line, t_elem *elem)
{
    ft_storage_xpm(line + 2, elem->NO);
}

int ft_parse_line(char *line, t_elem *elem)
{
    ft_elem_cmp(&line[i], elem);
}

int ft_parse_elem(int fd, t_elem *elem)
{
    ft_parse_line(line, elem);
}

int ft_parsing(int fd, t_elem *elem)
{
    ft_parse_elem(fd, elem);
}

int main()
{
    t_elem elem;

    elem = ft_init_elem();  //tout a null c'est que des ** et *
    ft_parsing(fd, &elem);
}