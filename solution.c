#include "./includes/fillit.h"

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

int check_space(char **mtx, t_tetra tetra, int x, int y)
{
	int xx;
	int yy;
	int start_x;

	start_x = x;
	yy = 0;
	while ((*tetra).h > yy)
	{
		xx = 0;
		while ((*tetra).w > xx)
		{
			if ((*tetra).tetraminka[yy][xx] != '.' && mtx[y][x] != '.')
				return (0);
			x++;
			xx++;
			if ((*tetra).tetraminka[yy][xx] == '\0')
				{
					y++;
					yy++;
					x = start_x;
				}
		}
	}
	return (1);
}

// int solution(char ***mtx, t_tetra tetra, int x, int y)
// {
// 	if (valid_exit())
// 		return (1);
// 	while(tetra->next)
//
// }
