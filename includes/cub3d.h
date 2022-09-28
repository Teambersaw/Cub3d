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
}  t_elem;

int    ft_parsing(int fd);

#endif