#ifndef SNAKE_H
# define SNAKE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>

# include "../mlx/mlxo/mlx.h"

# define W 30
# define H 20
# define WINDOWS_W 1920
# define WINDOWS_H 1280
# define MS 120000

typedef struct s_game {

	void				*mlx;
	void				*mlx_win;
	char				**map;
	struct	s_snake		*snake;
	struct	s_foods		*foods;
	int					points;
	int					rf;
}		t_game;

typedef struct s_foods {
	int	x;
	int	y;
	int	exists;
}		t_foods;

typedef struct s_snake {
	int	*head;
	int **body;
	int	direction;
}		t_snake;

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

char	*dalloc(size_t size, size_t count, char c);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_dotjoin(char const *s1, char const *s2, char *sep);
char	*ft_freejoin(char *s1, char *s2);

char	**ft_matmerge(char **arr1, char **arr2);
void	ft_cpmat(char **src, char **dst, int start);
int		ft_matlen(char **arr);
void	free_mat(char **mat);
void	print_mat(char **mat);

void	_init_rand();

void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	drawit(t_game *game);

int		key_filter(int keycode, t_game *game);

int		check_cond(t_game *game, int dir);
int		move_up(t_game *game);
int		move_down(t_game *game);
int		move_left(t_game *game);
int		move_right(t_game *game);
void	keep_direction(t_game *game);

void	snake_eat(t_game *game);
void	spawn_food(t_game *game);

void	debugf(t_game *game);
int 	end_game(t_game *game, int culo);

#endif
