#include <stdio.h>
#include <stdlib.h>

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

void print_mtx(int **i)
{
	int x, y;
	x = y = 0;
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
}
