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



int **solution(int **av_origin, int **av_copy, int x, int y, int i)
{
	i = 1;
	if (x == 8 && y == 8)
		return (av_copy);
	if (y == 9)
	{
		x++;
		y = 0;
	}
	if (ft_valid(av_copy, x, y, i) == 0)
	{
		if (y == 0 && x != 1)
			{
				x--;
				y = 8;
			}
		else
			y--;
		if (av_origin[x][y] == av_copy[x][y])
		{
			if (y == 0 && x != 1)
				{
					x--;
					y = 8;
				}
				else
					y--;
		}
		else solution(av_origin, av_copy, x, y, i);
	}
	else
	{
		while (i <= 9 || ft_valid(av_copy, x, y, i) > 0)
		{
			if (av_origin[x][y] == ac_copy[x][y])
				y++;
			else
				av_copy[x][y] = i;
			i++;
			y++;
		}
		solution(av_origin, av_copy, x, y, i);
	}
}
