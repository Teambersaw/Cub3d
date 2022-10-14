#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>

typedef struct s_pos
{
	float	x;
	float	y;
}	t_pos;

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
	int		fcolor;
	int		ccolor;
}	t_elem;

typedef struct s_img
{
	int		len;
	int		bpp;
	int		endian;
	void	*img;
	char	*addr;
}	t_img;

typedef struct s_player
{
	char		player;
	float		speed;
	t_pos		*pos;
}	t_player;

typedef struct s_map
{
	int			nb_player;
	char		**map;
	t_elem		*elem;
}	t_map;

typedef struct s_game
{
	int			size;
	void		*mlx;
	void		*mlx_win;
	t_map		*map;
	t_img		*img;
	t_player	*player;
}	t_game;

int			exit_game(t_game *game);
int			ft_mid_map(t_game *game);
int			ft_atoi_2(const char *nptr);
int			ft_verif_elem(t_elem *elem);
int			ft_verif_name(int ac, char **av);
int			ft_parse_elem(int fd, t_elem *elem);
int			do_event(int keycode, t_game *game);

char		*ft_strdup_2(char *src, char c);
char		**ft_parse_map(int fd, t_map *map, t_player *player);

void		move_up(t_game *game);
void		ft_color(t_elem *elem);
void		move_down(t_game *game);
void		move_left(t_game *game);
void		ft_free_tab(char **tab);
void		move_right(t_game *game);
void		init_window(t_game *game);
void		destroy_mlx(void *mlx, void *ptr, int mode);
void		ft_perror(char *str, int fd, char *line, t_map *map);
void		mlx_put_pixel(t_game *game, int x, int y, int color);
void		display_player(t_game *game, int x, int y, int color);
void		display_square(t_game *game, int x, int y, int color);
void		exit_msg(t_map *map, t_game *game, int exit_code, char *msg);
void		draw_rectangle(t_game *game, t_pos pos, t_pos dims, int color);

void		*ft_free_map(t_map *map);
void		*ft_free_game(t_game *game);

t_img		*init_img(void);

t_map		*ft_init_map(void);

t_game		*ft_parsing(int ac, char **av);

t_player	*init_player(void);

#endif
