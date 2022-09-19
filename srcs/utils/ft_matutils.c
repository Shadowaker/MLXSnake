#include "../../incl/snake.h"

/* Free a MATRIX (char **) and all of its contents.
RETURNS: void.*/
void	free_mat(char **mat)
{
	int	i;

	i = 0;
	while (mat[i] != NULL)
		free(mat[i++]);
	free(mat);
}

/* Print a MATRIX (char **) and all its contents
surrounded by § and NL.
RETURNS: void.*/
void	print_mat(char **mat)
{
	int	i;

	i = 0;
	for (int x = 0; x < W + 2; x++)
		write(1, "§", 3);
	write(1, "\n", 1);
	while (mat[i] != NULL)
		printf("§%s§\n", mat[i++]);
	for (int x = 0; x < W + 2; x++)
		write(1, "§", 3);
	write(1, "\n", 1);
	printf("\n");
}

/*
RETURNS: ARR (char **) length as int.*/
int	ft_matlen(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}

/* Copy a matrix (char **SRC) in the preallocated DST from
 a starting index of SRC.
RETURNS: void.*/
void	ft_cpmat(char **src, char **dst, int start)
{
	int	i;

	i = 0;
	while (src[i] != NULL)
	{
		dst[start] = ft_substr(src[i], 0, ft_strlen(src[i]));
		i++;
		start++;
	}
	dst[start] = NULL;
}

/* Merge two matrixes (char **) and free them.
RETURNS: a pointer to the new matrix (char **). */
char	**ft_matmerge(char **arr1, char **arr2)
{
	char	**res;

	res = malloc(sizeof(char *) * (ft_matlen(arr1) + ft_matlen(arr2)));
	ft_cpmat(arr1, res, 0);
	ft_cpmat(arr2, res, ft_matlen(arr1));
	free_mat(arr1);
	free_mat(arr2);
	return (res);
}
