#include <stdio.h>
#include <stdlib.h>

int checker_line (int *arr, int i);
int valid_x_y(int ***mtx, int x, int y);
int validation(int **arr, int x, int y, int ch);
void print_mtx(int **i);
int **to_int(char **argv);
int sqr_checker(int **mtx, int x, int y, int i);

int solution(int ***mtx, int x, int y)
{
	int i;
	if (y == 9)
		return (1);
	if ((*mtx)[y][x])
	{
		// valid_x_y(&x, &y);
		// if (solution(mtx, x, y))
		if (valid_x_y(mtx, x, y))
			return (1);
	}
	i = 0;
	while(++i <= 9)
	{
		if (validation(*mtx, x, y, i) && !(*mtx)[y][x])
		{
			(*mtx)[y][x] = i;
			if (valid_x_y(mtx, x, y))
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
	print_mtx(i);
	printf("____________________________________\n\n");
	solution(&i, 0, 0);
	print_mtx(i);
	printf("____________________________________\n\n");
	// while (x < 9)
	// 	{printf("%d", i[x][9]); x++;}
	// printf("\n");
	// x= 0;
	// while (x++ < 9)
	// {
	// 	if (checker_column(i, 9, x))
	// 		printf("x = %x GOOD\n", x);
	// 	else
	// 	printf("Trash\n");
	// }
	x = 0;
	while (x++ < 9)
		{
			if (validation(i, 8, 8, x))
			printf("%d", x);
		}
	return 0;
}
