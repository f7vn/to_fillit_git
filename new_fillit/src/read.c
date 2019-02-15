#include "../includes/fillit.h"
#include <stdio.h>
#include <stdlib.h>

int		l_back_push(t_tetra **start, t_tetra *data)
{
	t_tetra		*next_tetra;

	if (!data)
		return (1);
	next_tetra = *start;
	if(next_tetra)
	{
		while ((*next_tetra).next)
		 	next_tetra = (*next_tetra).next;
		(*next_tetra).next = data;
	}
	else
		*start = data;
	return (0);
}

// создаем эллемент

t_tetra		*create_ell(char ***elem)
{
	t_tetra *new_tetra;

	if (!(new_tetra = (t_tetra*)malloc(sizeof(t_tetra))))
	{
		ft_putendl("ERROR in create ell");
		return (NULL);
	}

	(*new_tetra).h = ft_clear_line(*elem);
	(*new_tetra).w = ft_clear_column(*elem);
	(*new_tetra).tetraminka = (*elem);
	(*new_tetra).next = NULL;
	return(new_tetra);
}

// valid connections

// int		lst_validation(char **mx, char ch)
// {
// 	int x;
// 	int y;
// 	int connect;
//
// 	x = 0;
// 	connect = 0;
// 	while (x < 4)
// 	{
// 		y = 0;
// 		while (y < 4)
// 		{
// 			if (mx[x][y] == ch)
// 			{
// 				if ((x + 1 < 4) && mx[x + 1][y] == ch)
// 					connect++;
// 				if ((x - 1 >= 0) && mx[x - 1][y] == ch)
// 					connect++;
// 				if ((y + 1 < 4) && mx[x][y + 1] == ch)
// 				 	connect++;
// 				if ((y - 1 >= 0) && mx[x][y - 1] == ch)
// 				 	connect++;
// 			}
// 			y++;
// 		}
// 		x++;
// 	}
// 	if (connect == 6 || connect == 8)
// 		{
// 			if (ch < 'Z')
// 			return  (1);
// 		}
// 	return (0);
// }

// заменяем на соответствующий символ и чекаем кол-во символов 4 sharp and 12 dots

// int ft_replace_and_check_valid_figure(char **mx, char ch)
// {
// 	int		x;
// 	int		y;
// 	int		sharps;
// 	int		dots;
//
// 	x = 0;
// 	sharps = 0;
// 	dots = 0;
// 	while(x < 4)
// 	{
// 		if (ft_strlen(mx[x]) != 4 || ((!mx[x + 1]) && (x + 1 < 4)))
// 			return (0);
// 		y = 0;
// 		while (y < 4)
// 		{
// 			if (mx[x][y] == '#')
// 			{
// 				mx[x][y] = ch;
// 				sharps++;
// 			}
// 			else if (mx[x][y] == '.')
// 				dots++;
// 			else
// 				return (1);
// 			y++;
// 		}
// 		x++;
// 	}
// 	if (dots != 12 || sharps != 4)
// 		return (1);
// 	return (0);
// }

//с помощью ГНЛ получаем  нашу карту и заносим в массив
// если 5ая строка не ноль - вернем положительное значение в последней строке возвращаем ноль

int		getarray(int fd, char ***arr, t_tetra **lists, char ch)
{
	int f;
	int i;

	i = 0;
	*arr = (char **)malloc(sizeof(char *) * 5);
	while(i < 4)
	{
		if (!get_next_line(fd, &((*arr)[i++])))
			ft_putendl("error in getarrayGNL");
	}
	if (!ft_replace_and_check_valid_figure(&arr[0][0], ch))
		ft_putendl("error in getarray");
	f = get_next_line(fd, &((*arr)[i]));
	(*arr)[i] = NULL;
	return (f);

}

//Получаем лист создаем эллемент

int		getlist(int fd, t_tetra **lists, t_tetra **list, char ch)
{
	int i;
	char **arr;

	arr = NULL;
	i = 0;

	i = getarray(fd, &arr, lists, ch);
	if (!lst_validation(arr, ch))
		ft_putendl("error in getlist");
	*list = create_ell(&arr);
	if (!wh_validation((*list)->w, (*list)->h))
		ft_putendl("error in getlist");
	return(i);
}

// Создаем поле с листами и пушим их назад

int		ft_create(int fd, t_tetra **lists)
{
	t_tetra		*list;
	char		ch;

	ch = 'A';
	while(getlist(fd, lists, &list, ch++))
		l_back_push(lists, list);
	l_back_push(lists, list);
	return (0);
}

//читаем файл

int		ft_read(char *line, t_tetra **lists)
{
	int		fd;

	fd = open(line, O_RDONLY);
	if (line && fd)
		ft_create(fd, lists);
	else
		ft_putendl("Crash in ft_read");
	return (0);
}
