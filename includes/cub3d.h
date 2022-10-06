#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_elem
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	**f;
	char	**c;
	int		nb_elem;
	int		fr;
	int		fg;
	int		fb;
	int		cr;
	int		cg;
	int		cb;
}	t_elem;

typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
	char	player;
	int		nb_player;
	t_elem	elem;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	t_map	*map;
}	t_game;

// -----------------------------PARSING-----------------------------

int			ft_mid_map(t_map *map);
int			ft_atoi_2(const char *nptr);
int			ft_verif_elem(t_elem *elem);
int			ft_verif_name(int ac, char **av);
int			ft_parse_elem(int fd, t_elem *elem);

char		*ft_strdup_2(char *src, char c);
char		**ft_parse_map(int fd, t_map *map);

void		ft_free_map(t_map *map);
void		ft_free_tab(char **tab);
void		ft_init_map(t_game *game);
void		ft_perror(char *str, int fd, char *line, t_map *map);

t_elem		ft_init_elem(void);

t_game		*ft_init_game(void);
t_game		*ft_parsing(int ac, char **av);

#endif