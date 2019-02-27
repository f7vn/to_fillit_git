#include "./includes/fillit.h"
#include "./includes/libft.h"
#include <stdio.h>

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
	//
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

	sh = ft_n_sharps(&lists);
	printf("%d\n", sh);

	sh = the_biggest_sqwr(sh);
	printf("%d\n", sh);

	map = ft_create_map(sh);

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
