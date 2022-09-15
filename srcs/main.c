
#include "../incl/snake.h"

int end_game(t_game *game, int culo)
{
	if (game && culo)
		;
	exit(0);
}

char	**map_init()
{
	int		i;
	char	*s;
	char	**map;

	map = calloc(sizeof(char *), H + 1);
	for (i = 0; i < H; i++)
	{
		s = dalloc(1, W, ' ');
		map[i] = s;
	}
	return map;
}

void	snake_init(t_game *game)
{
	t_snake	*snake;
	int		*tmp;
	int		*tmp2;
	int		**body;

	snake = malloc(sizeof(t_snake));
	tmp = calloc(sizeof(int), 2);
	tmp[0] = 10;
	tmp[1] = 10;
	snake->head = tmp;
	body = calloc(sizeof(int *), 100);
	body[0] = tmp;
	tmp2 = calloc(sizeof(int), 2);
	tmp2[0] = 10;
	tmp2[1] = 11;
	body[1] = tmp2;
	snake->body = body;
	snake->direction = -1;
	game->snake = snake;
}

void	_init(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, WINDOWS_W, WINDOWS_H, "Snake");
	game->rf = 1;
	game->map = map_init();
	game->map[10][10] = 'S';
	game->map[11][10] = 'S';
	game->map[5][5] = 'G';
	snake_init(game);
}

void	draw_piece(t_img *img, int x, int y, int color)
{
	int	i;
	int	j;

	for (i = 0; i <= 64; i++)
	{
		for (j = 0; j <= 64; j++)
		{
			my_mlx_pixel_put(img, x + i, y + j, color);
		}
	}
}

void	drawit(t_game *game)
{
	t_img	img;
	int		i;
	int		j;

	img.img = mlx_new_image(game->mlx, WINDOWS_W, WINDOWS_H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	for (i = 0; i < H; i++)
	{
		for (j = 0; j < W; j++)
		{
			if (game->map[i][j] == 'S')
				draw_piece(&img, j * 64, i * 64, 0x00FF0000);
			else if (game->map[i][j] == 'G')
				draw_piece(&img, j * 64, i * 64, 0x0000FF00);
		}
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, img.img, 0, 0);
}

int	game_loop(t_game *game)
{
	drawit(game);
	keep_direction(game);
	usleep(MS);
	return (0);
}

int	main(void)
{
	t_game	game;

	_init(&game);
	mlx_hook(game.mlx_win, 17, 0, end_game, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_key_hook(game.mlx_win, key_filter, &game);
	mlx_loop(game.mlx);
}
