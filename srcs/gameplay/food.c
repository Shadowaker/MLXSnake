
#include "../../incl/snake.h"

void	spawn_food(t_game *game)
{
	int	i = -1;
	int	j = -1;

	while (i < 0 || j < 0 || i > H || j > W)
	{
		// rand() % (upper - lower + 1)) + lower
		i = rand() % ((30 - 0 + 1) + 0);
		j = rand() % ((30 - 0 + 1) + 0);
		if (i >= 0 && j >= 0 && i < H && j < W)
		{
			if (game->map[i][j] != 'S')
				continue ;
		}
		i = -1;
		j = -1;
	}
	game->foods->y = i;
	game->foods->x = j;
	game->foods->exists = 1;
	game->map[i][j] = 'G';
}

