

#include "../incl/snake.h"

/*
Alloc size * count memory and fill it with a char c.
*/
char	*dalloc(size_t size, size_t count, char c)
{
	char	*s;
	size_t	i;

	s = calloc(size, count + 1);
	for (i = 0; i < count; i++)
		s[i] = c;
	return s;
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
