
#include "../incl/snake.h"

int end_game(t_game *game, int culo)
{
	if (game && culo)
		;
	drawit(game);
	usleep(MS * 2);
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

void	food_init(t_game *game)
{
	spawn_food(game);
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
	game->mlx_win = mlx_new_window(game->mlx, WINDOWS_W + 8, WINDOWS_H + 72, "Snake");
	game->rf = 1;
	game->points = 0;
	game->map = map_init();
	game->map[10][10] = 'S';
	game->map[11][10] = 'S';
	food_init(game);
	snake_init(game);
}

int	game_loop(t_game *game)
{
	if (game->rf == 0)
		keep_direction(game);
	else
		game->rf = 0;
	usleep(MS - 40000);
	drawit(game);
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
