#include "../../incl/snake.h"


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

	img.img = mlx_new_image(game->mlx, WINDOWS_W + 8, WINDOWS_H + 8);
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
