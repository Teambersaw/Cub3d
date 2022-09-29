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
    int     index;
    int     FR;
    int     FG;
    int     FB;
    int     CR;
    int     CG;
    int     CB;
}  t_elem;

void	    ft_free_tab(char **tab);
int         ft_verif_elem(t_elem *elem);
void        ft_free_elem(t_elem elem);

void        ft_perror(char *str, int fd, char *line);

int         ft_parsing(int fd, t_elem *elem);

t_elem      ft_init_elem();

#endif