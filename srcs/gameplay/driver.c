
#include "../incl/snake.h"

void	keep_direction(t_game *game)
{
	if (game->snake->direction != -1)
	{
		if (game->snake->direction == 0)
		{
		if (!check_cond(game, 0))
			move_up(game);
		else
			end_game(game, 0);
		}
		else if (game->snake->direction == 1)
		{
		if (!check_cond(game, 1))
			move_left(game);
		else
			end_game(game, 0);
		}
		else if (game->snake->direction == 2)
		{
		if (!check_cond(game, 2))
			move_down(game);
		else
			end_game(game, 0);
		}
		else if (game->snake->direction == 3)
		{
		if (!check_cond(game, 3))
			move_right(game);
		else
			end_game(game, 0);
		}
		debugf(game);
	}
}
