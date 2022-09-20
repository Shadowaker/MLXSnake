#include  "../../incl/snake.h"

void	snake_eat(t_game *game)
{
	int	*tail;
	int	i = 0;

	while (game->snake->body[i] != NULL)
	{
		i++;
	}
	tail = calloc(sizeof(int), 2);
	tail[0] = game->snake->body[i - 1][0];
	tail[1] = game->snake->body[i - 1][1];
	game->snake->body[i] = tail;
	game->foods->exists = 0;
}
