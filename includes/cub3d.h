#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct   s_elem
{
    char    *NO;
    char    *SO;
    char    *WE;
    char    *EA;
    char    **F;
    char    **C;
    int     nb_elem;
    int     FR;
    int     FG;
    int     FB;
    int     CR;
    int     CG;
    int     CB;
}   t_elem;

typedef struct  s_map
{
    char    **map;
    int     x;
    int     y;
    char    player;
    int     nb_player;
}   t_map;

int	        ft_atoi_2(const char *nptr);
int         ft_verif_elem(t_elem *elem);
int         ft_parsing(int fd, t_elem *elem);
int         ft_atoi_3(const char *nptr, int nb, int minus);
char        **ft_parse_map(int fd, t_map *map);
char        *ft_strdup_2(char *src, char c);
void	    ft_free_tab(char **tab);
void        ft_free_elem(t_elem elem);
void        ft_perror(char *str, int fd, char *line);

t_elem      ft_init_elem();
t_map       ft_init_map();

#endif