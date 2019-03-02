#include <stdio.h>
#include <stdlib.h>
//
int solution(int ***mtx, int x, int y);
int checker_line (int *arr, int i)
{
	int x = 0;
	while(x < 9)
	{
		//printf("vnutri x = %d\t i = %d\n", x, i);
		if (arr[x] == i)
				return (0);
		x++;
	}
	return (1);
}

int checker_column(int **arr, int x, int i)
{
	// printf("I - %d", i);
	int y = -1;
	while(++y < 9)
	{
		if(arr[y][x] == i)
			return (0);
	}
	return (1);
}

int sqr_checker(int **mtx, int x, int y, int i)
{
	// int xx;
	// int yy;
	// yy = 0;
	// while (yy < 3)
	// {
	// 	xx = 0;
	// 	while (xx < 3)
	// 	{
	// 		if (mtx[x / 3 * 3 + xx][y / 3 * 3 + yy] == i)
	// 			return (0);
	// 		xx++;
	// 	}
	// 	yy++;
	// }
	return (1);
}

int validation(int **arr, int x, int y, int ch)
{

	if (checker_line(arr[y], ch) && checker_column(arr, x, ch) && sqr_checker(arr, x, y, ch))
		return (1);
	// printf("checker_line - %d\n", checker_line(arr[x],  x, ch));
	// printf("checker_column - %d\n", checker_column(arr, x, y, ch));
	return (0);
}

int valid_x_y(int ***mtx, int x, int y)
{
	x++;
	if (x > 8)
	{
		y++;
		x = 0;
	}
	if (solution(mtx, x, y))
		return (1);
	return (0);
}
