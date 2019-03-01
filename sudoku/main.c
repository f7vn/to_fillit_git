#include <stdio.h>

int checker_sqr(int **arr, int i, int x, int y)
{
	// int x;
	// int y;
	//
	// int a;
	// int b;
	//
	// a = x % 3;
	// b = y % 3;
	//
	// while (a < 3)
	// {
	// 	//	printf("%c\n", arr[x][y]);
	// 		while (b < 3)
	// 		{
	// 			printf("%c", arr[x][y]);
	// 			if (arr[x][y] == i)
	// 				return (0);
	// 			b++;
	// 		}
	// 		b = 0;
	// 		printf("\n");
	// 	x++;
	// }
	return (1);
}

int checker_line (int *arr, int i, int x)
{
	while(arr[x++])
	{
		if (arr[x] == i)
				return (0);
	}
	return (1);
}

int checker_column(int **arr, int i, int x, int y)
{
	while(x <= 9)
	{
		if(arr[x][y] == i)
			return (0);
		x++;
	}
	return (1);
}

int validation(int **arr, int ch, int x, int y)
{
	if (checker_sqr(arr, ch, x, y) && checker_line(arr[x + 1], ch, 2) && checker_column(arr, ch, x + 1, y))
		return (1);

	return (0);
}

void sudoku(char **arr)
{

	int x;
	x = 0;
	if (checker_sqr(arr, '5', 0 , 0))
		printf("Квадрант YES\n");
	else
		printf("Kvadrant NO\n");
	if (checker_line(arr[1], '5', 2))
		printf("line YES\n");
	else
		printf("line NO\n");
	if (checker_column(arr, '5', 0, 0))
		printf("column YES\n");
	else
		printf("column NO\n");
	if (validation(arr, '5', 0, 0))
		printf("final YES\n");
	else
		printf("final NO\n");
}

int main(int argc, char *argv[])
{
	if (argc == 10)
		sudoku(argv);
	else
		return (1);
	return 0;
}
