
#include "../incl/snake.h"

void	keep_direction(t_game *game)
{
	if (game->snake->direction != -1)
	{
		if (game->snake->direction == 0)
			key_filter(13, game);
		else if (game->snake->direction == 1)
			key_filter(0, game);
		else if (game->snake->direction == 2)
			key_filter(1, game);
		else if (game->snake->direction == 3)
			key_filter(2, game);
	}
}
