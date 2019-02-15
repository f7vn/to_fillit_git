#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


// static int		clear_line(char *line)
// {
// 	while (*line)
// 	{
// 		if (*line != '.')
// 			return (0);
// 		line++;
// 	}
// 	return (1);
// }
//
// int		erase_line(char **mx)
// {
// 	int x;
// 	int y;
//
// 	y = 0;
// 	while (mx[y])
// 	{
// 		if (clear_line(mx[y]))
// 		{
// 			free(mx[y]);
// 			printf("1\n");
// 			x = y + 1;
// 			while(mx[x])
// 			{
// 				printf("x = %d\n", x);
// 				mx[x - 1] = mx[x];
// 				x++;
// 			}
// 			mx[x - 1] = mx[x];
// 			continue;
// 		}
// 		y++;
// 	}
// 	return (y);
// }
//
// int		clear_coll(char **mx, int n)
// {
// 	int y;
//
// 	y = 0;
// 	while(mx[y])
// 	{
// 		if(mx[y][n] != '.')
// 			return (0);
// 		y++;
// 	}
// 	return (1);
// }
//
// int erase_column(char **mx)
// {
// 	int x;
// 	int y;
// 	int n;
//
// 	n = 0;
// 	while (mx[0][n])
// 	{
// 		if (clear_coll(mx, n))
// 		{
// 			y = 0;
// 			while (mx[y])
// 			{
// 				x = ++n;
// 				while (mx[y][x])
// 				{
// 					mx[y][x-1] = mx[y][x];
// 					x++;
// 				}
// 				mx[y][x - 1] = mx[y][x];
// 				y++;
// 			}
// 			continue;
// 		}
// 		n++;
// 	}
// 	return (n);
// }


static int		clear_line(char *str)
{
	char c = '.';
	while (*str)
	{
		if (*str != c)
			return (0);
		str++;
	}
	return (1);
}

static int		clear_coll(char **matrix, int n)
{
	int		y;
	char c = '.';
	y = 0;
	while (matrix[y])
	{
		if (matrix[y][n] != c)
			return (0);
		y++;
	}
	return (1);
}

int				erase_line(char **matrix)
{
	int		y;
	int		x;

	y = 0;
	while (matrix[y])
	{
		if (clear_line(matrix[y]))
		{
			free(matrix[y]);
			x = y + 1;
			while (matrix[x])
			{
				matrix[x - 1] = matrix[x];
				x++;
			}
			matrix[x - 1] = matrix[x];
			continue ;
		}
		y++;
	}
	return (y);
}

int				erase_column(char **matrix)
{
	int		n;
	int		y;
	int		x;

	n = 0;
	while (matrix[0][n])
	{
		if (clear_coll(matrix, n))
		{
			y = -1;
			while (matrix[++y])
			{
				x = n + 1;
				while (matrix[y][x])
				{
					matrix[y][x - 1] = matrix[y][x];
					x++;
				}
				matrix[y][x - 1] = matrix[y][x];
			}
			continue;
		}
		n++;
	}
	return (n);
}
