#include "./includes/fillit.h"
#include "./includes/libft.h"
#include <stdio.h>

int check_space(char **mtx, t_tetra *tetra, int x, int y);
int put_tetra(char **mtx, t_tetra *tetra, int x, int y);
int dell_tetra(char **mtx, t_tetra *tetra, int x, int y);
int solution(char **mtx, t_tetra *tetra, int x, int y, int sqr);

int		ft_fillit(char *line)
{
	t_tetra	*lists;
	int i;
	int j;
	int n;
	int sh;
	char **map;

	lists = NULL;
	ft_read(line, &lists);
	ft_putendl("everythingOk");
	// printf("%d\n", lists->h);
	// printf("%d\n", lists->w);

	// while (lists->next)
	// {
	// 	i = 0;
	// 	j = 0;
	// 	while (lists->tetraminka[j])
	// 	{
	// 		i = 0;
	// 		while(lists->tetraminka[j][i])
	// 			printf("%c", lists->tetraminka[j][i++]);
	// 		printf("\n");
	// 		j++;
	// 	}
	// 	lists = lists->next;
	// 		printf("\n");
	// }
	//
	// i = 0;
	// j = 0;
	// while (lists->tetraminka[j])
	// {
	// 	i = 0;
	// 	while(lists->tetraminka[j][i])
	// 		printf("%c", lists->tetraminka[j][i++]);
	// 	printf("\n");
	// 	j++;
	// }

	sh = ft_n_sharps(lists);
	printf("sharp = %d\n", sh);

	sh = the_biggest_sqwr(sh);
	printf("%d\n", sh);

	map = ft_create_map(sh);

	i = check_space(map, lists, 0, 0);
	i = put_tetra(map, lists, 0, 0);
	i = dell_tetra(map, lists, 0, 0);
	ft_putendl("test");
	printf("valid %d\n", i);
	printf("Print map\n");
	i = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	// ft_solve(lists);
	printf("___________________________________\n");
	i = 0;
	while(!solution(map, lists, 0, 0, sh))
			{printf("%s\n", "\n\n\nNes wave\n\n\n");
			map = ft_create_map(++sh);}
	printf("solu%d\n", i);
	i = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}

	return (0);
}

int		main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file");
		return(1);
	}
	else
		ft_fillit(argv[1]);
	return (0);
}
