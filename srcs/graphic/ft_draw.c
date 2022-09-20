#include "../../incl/snake.h"

void	draw_string(t_game *game, int *arr, char *s, int offset)
{
	mlx_string_put(game->mlx, game->mlx_win, arr[0] * 30,
		(arr[1] * 30) + offset, 0x0FFFFFFF, s);
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

void	draw_points(t_game *game)
{
	char	*points;
	char	*s;
	int		arr[2] = {20, WINDOWS_H + 20};

	points = ft_itoa(game->points);
	s = ft_strjoin("POINTS: ", points);
	free(points);
	draw_string(game, arr, s, 0);
	free(s);
}

void	drawit(t_game *game)
{
	t_img	img;
	int		i;
	int		j;

	img.img = mlx_new_image(game->mlx, WINDOWS_W + 8, WINDOWS_H + 74);
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
	for (i = 0; i < WINDOWS_W; i++)
		my_mlx_pixel_put(&img, i, WINDOWS_H, 0x00FF0000);
	draw_points(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img.img, 0, 0);
}
