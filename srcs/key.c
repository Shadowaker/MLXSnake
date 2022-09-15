
#include "../incl/snake.h"


int	check_cond(t_game *game, int dir)
{
	if (dir == 0 && game->snake->head[1] == 0)
		return (1);
	else if (dir == 1 && game->snake->head[0] == 0)
		return (1);
	else if (dir == 2 && game->snake->head[1] == H)
		return (1);
	else if (dir == 3 && game->snake->head[0] == W)
		return (1);
	return (0);
}


int	move_up(t_game *game)
{
	int	*tmp;
	int	*tmp2;
	int	i;

	tmp = calloc(sizeof(int *), 2);
	tmp[0] = game->snake->head[0];
	tmp[1] = game->snake->head[1];
	game->snake->head[1] -= 1;
	game->map[game->snake->head[1]][game->snake->head[0]] = 'S';
	for (i = 1; game->snake->body[i] != NULL; i++)
	{
		if (game->snake->body[i + 1] == NULL)
			game->map[game->snake->body[i][1]][game->snake->body[i][0]] = ' ';
		tmp2 = calloc(sizeof(int *), 2);
		tmp2[0] = game->snake->body[i][0];
		tmp2[1] = game->snake->body[i][1];
		game->snake->body[i][0] = tmp[0];
		game->snake->body[i][1] = tmp[1];
		game->map[game->snake->body[i][1]][game->snake->body[i][0]] = 'S';
		free(tmp);
		tmp = tmp2;
	}
	free(tmp);
	game->snake->direction = 0;
	return (0);
}


int	move_down(t_game *game)
{
	int	*tmp;
	int	*tmp2;
	int	i;

	tmp = calloc(sizeof(int *), 2);
	tmp[0] = game->snake->head[0];
	tmp[1] = game->snake->head[1];
	game->snake->head[1] += 1;
	game->map[game->snake->head[1]][game->snake->head[0]] = 'S';
	for (i = 1; game->snake->body[i] != NULL; i++)
	{
		if (game->snake->body[i + 1] == NULL)
			game->map[game->snake->body[i][1]][game->snake->body[i][0]] = ' ';
		tmp2 = calloc(sizeof(int *), 2);
		tmp2[0] = game->snake->body[i][0];
		tmp2[1] = game->snake->body[i][1];
		game->snake->body[i][0] = tmp[0];
		game->snake->body[i][1] = tmp[1];
		game->map[game->snake->body[i][1]][game->snake->body[i][0]] = 'S';
		free(tmp);
		tmp = tmp2;
	}
	free(tmp);
	game->snake->direction = 1;
	return (0);
}


int	move_right(t_game *game)
{
	int	*tmp;
	int	*tmp2;
	int	i;

	tmp = calloc(sizeof(int *), 2);
	tmp[0] = game->snake->head[0];
	tmp[1] = game->snake->head[1];
	game->snake->head[0] += 1;
	game->map[game->snake->head[1]][game->snake->head[0]] = 'S';
	for (i = 1; game->snake->body[i] != NULL; i++)
	{
		if (game->snake->body[i + 1] == NULL)
			game->map[game->snake->body[i][1]][game->snake->body[i][0]] = ' ';
		tmp2 = calloc(sizeof(int *), 2);
		tmp2[0] = game->snake->body[i][0];
		tmp2[1] = game->snake->body[i][1];
		game->snake->body[i][0] = tmp[0];
		game->snake->body[i][1] = tmp[1];
		game->map[game->snake->body[i][1]][game->snake->body[i][0]] = 'S';
		free(tmp);
		tmp = tmp2;
	}
	free(tmp);
	game->snake->direction = 3;
	return (0);
}


int	move_left(t_game *game)
{
	int	*tmp;
	int	*tmp2;
	int	i;

	tmp = calloc(sizeof(int *), 2);
	tmp[0] = game->snake->head[0];
	tmp[1] = game->snake->head[1];
	game->snake->head[0] -= 1;
	game->map[game->snake->head[1]][game->snake->head[0]] = 'S';
	for (i = 1; game->snake->body[i] != NULL; i++)
	{
		if (game->snake->body[i + 1] == NULL)
			game->map[game->snake->body[i][1]][game->snake->body[i][0]] = ' ';
		tmp2 = calloc(sizeof(int *), 2);
		tmp2[0] = game->snake->body[i][0];
		tmp2[1] = game->snake->body[i][1];
		game->snake->body[i][0] = tmp[0];
		game->snake->body[i][1] = tmp[1];
		game->map[game->snake->body[i][1]][game->snake->body[i][0]] = 'S';
		free(tmp);
		tmp = tmp2;
	}
	free(tmp);
	game->snake->direction = 0;
	return (0);
}


int	key_filter(int keycode, t_game *game)
{
	int	i;

	i = 0;
	if (keycode == 53)
		end_game(game, 0);
	else if (keycode == 13 || keycode == 126)
	{
		if (!check_cond(game, 0))
			move_up(game);
		else
			end_game(game, 0);
	}
	else if (keycode == 0 || keycode == 123)
	{
		if (!check_cond(game, 1))
			move_left(game);
		else
			end_game(game, 0);
	}
	else if (keycode == 1 || keycode == 125)
	{
		if (!check_cond(game, 2))
			move_down(game);
		else
			end_game(game, 0);
	}
	else if (keycode == 2 || keycode == 124)
	{
		if (!check_cond(game, 3))
			move_right(game);
		else
			end_game(game, 0);
	}
	printf("\033[93m[DEBUG]\033[0m -----------------------------------------------------\n");
	for (i = 0; game->snake->body[i] != NULL; i++)
		printf("\033[93m[DEBUG]\033[0m body: %d - x: %d - y: %d\n", i, game->snake->body[i][0], game->snake->body[i][1]);
	return (0);
}
