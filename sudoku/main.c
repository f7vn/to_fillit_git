#include <stdio.h>

int checker_sqr(char **arr, char i)
{
	int x;
	int y;
	x = 1;
	while (x <= 3)
	{
		y = 0;
		//	printf("%c\n", arr[x][y]);
			while (y < 3)
			{
				printf("%c", arr[x][y]);
				if (arr[x][y] == i)
					return (0);
				y++;
			}
			printf("\n");
		x++;
	}
	return (1);
}

int checker_line (char *arr, char i)
{
	int x;

	while(arr[x++])
	{
		if (arr[x] == i)
				return (0);
	}
	return (1);
}

int checker_column(char **arr, char i, int x, int y)
{
	while(x <= 8)
	{
		if(arr[x][y] == i)
			return (0);
		x++;
	}
	return (1);
}

int validation(char **arr, char ch, int x, int y)
{
	if (checker_sqr(arr, ch) && checker_line(arr[1], ch) && checker_column(arr, ch, x, y))
		return (1);
	return (0);
}

void sudoku(char **arr)
{

	int x;
	x = 0;
	if (checker_sqr(arr, '5'))
		printf("Квадрант YES\n");
	else
		printf("Kvadrant NO\n");
	if (checker_line(arr[1], '5'))
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
