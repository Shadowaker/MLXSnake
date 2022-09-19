#include  "../../incl/snake.h"

void	snake_eat(t_game *game)
{
	int	*tail;
	int	i = 0;

	while (game->snake->body[i + 1] != NULL)
	{
		i++;
	}
	tail = calloc(sizeof(int), 2);
	tail[0] = game->snake->body[i][0];
	tail[1] = game->snake->body[i][1];
	game->snake->body[i + 1] = tail;
	game->foods->exists = 0;
}
