void	ft_tetdel(t_tetris **alst)
{
	t_tetris	*tmp;
	t_tetris	*lst;

	lst = *alst;
	while (lst)
	{
		tmp = lst->next;
		ft_clear_mrx(lst->piece);
		(void)lst->width;
		(void)lst->heigth;
		lst->next = NULL;
		free(lst);
		lst = NULL;
		lst = tmp;
	}
	*alst = NULL;
}

int		ft_clear_lists(t_tetra **lst)
{
	if (lst == NULL)
		return (1);
	ft_clear_mtx((*lst)->tetraminka);
	free((*lst)->tetraminka);
	(*lst)->tetraminka = NULL;
	ft_clear_lists((*lst)->next);
	(*lst)->next = NULL;
	free(*lst);
	*lst = NULL;
	return (0);
}
