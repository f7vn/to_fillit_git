#include <stdio.h>
#include <stdlib.h>

int checker_line (int *arr, int i)
{
	int x = -1;
	while(arr[++x] && x < 9)
	{
		if (arr[x] == i)
				return (0);
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

int validation(int **arr, int x, int y, int ch)
{

	if (checker_line(arr[x], ch) && checker_column(arr, x, ch))
		return (1);
	// printf("checker_line - %d\n", checker_line(arr[x],  x, ch));
	// printf("checker_column - %d\n", checker_column(arr, x, y, ch));
	return (0);
}


int **to_int(char **argv)
{
	int x;
	int y;
	int **av_origin;

	x = 0;
	av_origin = malloc(sizeof(int*) * 9);
	while(x < 9)
		av_origin[x++] = malloc(sizeof(int) * 9);
	x = 0;
	while (x < 9)
	{
		y = 0;
		while (y < 9)
		{
			if (argv[x][y] == '.')
				av_origin[x][y] = 0;
			else
			 	av_origin[x][y] = argv[x][y] - '0';
			y++;
		}
		x++;
	}
	return (av_origin);
}

// int **solution(int **av_origin, int **av_copy, int x, int y, int i)
// {
// 	printf("start solution: x = %d\ty = %d\ti = %d\n",x,y,i);
// 	i = 1;
// 	if (x == 8 && y == 8)
// 		return (av_copy);
// 	if (y == 9)
// 	{
// 		x++;
// 		y = 0;
// 	}
// 	printf("valid - %d\n", validation(av_copy, x, y, i));
// 	if (validation(av_copy, x, y, i) == 0)
// 	{
// 		printf("1\n" );
// 		if (y == 0 && x != 0)
// 			{
// 				printf("1.1\n" );
// 				x--;
// 				y = 8;
// 			}
// 		else
// 		{
// 			printf("1.2\n" );
// 			y--;
// 		}
// 		if (av_origin[x][y] == av_copy[x][y] && av_origin[x][y] != 0)
// 		{
// 			printf("1.3\n");
// 			printf("x = %d\n", x);
// 			printf("y = %d\n", y);
// 			printf("copy = %d\n", av_copy[x][y]);
// 			printf("i = %d\n", i);
// 			if (y == 0 && x != 0)
// 				{
// 					x--;
// 					y = 8;
// 				}
// 				else
// 					y--;
// 		}
// 		else solution(av_origin, av_copy, x, y, i);
// 	}
// 	else
// 	{
// 		printf("2\n" );
// 		while (i <= 9 && validation(av_copy, x, y, i) > 0)
// 		{
// 			printf("3\n" );
// 			if (av_origin[x][y] != 0 && av_origin[x][y] == av_copy[x][y])
// 				{
// 					printf("Одинаковое\n" );
// 					y++;
// 				}
//
// 			else
// 				{
// 					printf("Замена\n" );
// 					av_copy[x][y] = i;
// 				}
//
// 			i++;
// 			y++;
// 		}
// 		solution(av_origin, av_copy, x, y, i);
// 	}
// 	return (av_copy);
// }

void valid_x_y(int *x, int *y)
{
	(*x)++;
	if (*x > 8)
	{
		(*y)++;
		(*x) = 0;
	}
}

int solution(int ***mtx, int x, int y)
{
	int i;
	if (y == 9)
		return (1);
	if ((*mtx)[y][x])
	{
		valid_x_y(&x, &y);
		if (solution(mtx, x, y))
			return (1);
	}
	i = 0;
	while(++i <= 9)
	{
		if (validation(*mtx, x, y, i) && !(*mtx)[y][x])
		{
			(*mtx)[y][x] = i;
			valid_x_y(&x, &y);
			if (solution(mtx, x, y))
				return (1);
			(*mtx)[y][x] = 0;
		}
	}
	return (0);
}


int main(int argc, char *argv[])
{
	int **i;
	int x, y;
	x = y = 0;
	i = to_int(++argv);
		while (x < 9)
		{
			y = 0;
			while (y < 9)
			{
				printf("%d", i[x][y]);
				y++;
			}
			printf("\n");
			x++;
		}
		printf("____________________________________\n");
		solution(&i, 0, 0);

			x = 0;
			y = 0;
			while (x < 9)
			{
				y = 0;
				while (y < 9)
				{
					printf("%d", i[x][y]);
					y++;
				}
				printf("\n");
				x++;
			}
	return 0;
}
