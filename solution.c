#include "./includes/fillit.h"
#include <stdio.h>
// int valid_x_y(int ***mtx, t_tera tetra, int x, int y)
// {
// 	x++;
// 	if (x > 8)
// 	{
// 		y++;
// 		x = 0;
// 	}
// 	if (solution(mtx, tetra, x, y))
// 		return (1);
// 	return (0);
// }

int check_space(char **mtx, t_tetra *tetra, int x, int y)
{
	int xx;
	int yy;
	int start_x;
	start_x = x;

	yy = 0;
	// printf("%d\n", tet->h);
	while (tetra->h > yy)
	{
		xx = 0;
		while (tetra->w > xx)
		{
			if ((tetra->tetraminka)[yy][xx] != '.' && mtx[y][x] != '.')
				return (0);
			x++;
			xx++;
			if ((tetra->tetraminka)[yy][xx] == '\0')
			{
				y++;
				yy++;
				x = start_x;
			}
		}
	}
	return (1);
}

int put_tetra(char **mtx, t_tetra *tetra, int x, int y)
{
	int xx;
	int yy;
	int start_x;
	start_x = x;

	yy = 0;
	// printf("%d\n", tet->h);
	while (tetra->h > yy)
	{
		xx = 0;
		while (tetra->w > xx)
		{
			if (mtx[y][x] == '.')
				mtx[y][x] = (tetra->tetraminka)[yy][xx];
			x++;
			xx++;
			if ((tetra->tetraminka)[yy][xx] == '\0')
			{
				y++;
				yy++;
				x = start_x;
			}
		}
	}
	return (1);
}

int dell_tetra(char **mtx, t_tetra *tetra, int x, int y)
{
	int xx;
	int yy;
	int start_x;
	start_x = x;

	yy = 0;
	// printf("%d\n", tet->h);
	while (tetra->h > yy)
	{
		xx = 0;
		while (tetra->w > xx)
		{
			if (mtx[y][x] == (tetra->tetraminka)[yy][xx])
				mtx[y][x] = '.';
			x++;
			xx++;
			if ((tetra->tetraminka)[yy][xx] == '\0')
			{
				y++;
				yy++;
				x = start_x;
			}
		}
	}
	return (1);
}

int solution(char **mtx, t_tetra *tetra, int x, int y, int sqr)
{
	if (!tetra)
		return (1);
	while (tetra->h + y <= sqr)
	{
		while (tetra->w + x <= sqr)
		{
			if (check_space(mtx, tetra, x, y))
			{
				// printf("check_space - %d\n", check_space(mtx, tetra, x, y));
				// printf("y = %d, x = %d\n", y, x);
				put_tetra(mtx, tetra, x, y);
				// printf("put_tetra\n");
				// printf("x - %d\n", x);
				if (solution(mtx, tetra->next, 0, 0, sqr))
					return (1);
				dell_tetra(mtx, tetra, x, y);
				// printf(" dell tetra y = %d, x = %d\n", y, x);
			}
			// printf("second circle x = %d\n", x);
			x++;
		}
		// printf("y - %d\n", y);
		y++;
		x = 0;
	}
	return (0);
}
