#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>

typedef struct s_img
{
	char	value;
	char	*path;
	void	*img;
}	t_img;

typedef struct s_assets
{
	int		size;
	t_img	wall;
	t_img	empty;
}	t_assets;

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
	char		**map;
	int			x;
	int			y;
	int			size_x;
	int			size_y;
	char		player;
	int			nb_player;
	t_elem		*elem;
	t_assets	assets;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	t_map	*map;
}	t_game;


// -----------------------------PARSING-----------------------------

int			ft_mid_map(t_map *map);
int			exit_game(t_game *game);
int			ft_atoi_2(const char *nptr);
int			ft_verif_elem(t_elem *elem);
int			ft_verif_name(int ac, char **av);
int			ft_parse_elem(int fd, t_elem *elem);
int			do_event(int keycode, t_game *game);

char		*ft_strdup_2(char *src, char c);
char		**ft_parse_map(int fd, t_map *map);

void		ft_free_tab(char **tab);
void		ft_init_map(t_map *map);
void		ft_init_elem(t_elem *elem);
void		destroy_mlx(void *mlx, void *ptr, int mode);
void		ft_perror(char *str, int fd, char *line, t_map *map);
void		exit_msg(t_map *map, t_game *game, int exit_code, char *msg);

void		*ft_free_map(t_map *map);
void		*ft_free_game(t_game *game);

t_map		*ft_parsing(int ac, char **av);

t_game		*init_game(t_map *map);

#endif