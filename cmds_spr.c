#include "push_swap.h"

void	sa(t_llist *list, char c)
{
	int	tmp;
	int	tmp_i;

	tmp = list->content;
	tmp_i = list->index;
	list->content = list->next->content;
	list->index = list->next->index;
	list->next->content = tmp;
	list->next->index = tmp_i;
	if (c == 'a')
		ft_printf("sa\n");
	else if (c == 'b')
		ft_printf("sb\n");
}

void	ss(t_llist *a, t_llist *b)
{
	sa(a, 0);
	sa(b, 0);
	ft_printf("ss\n");
}

void	pa(t_llist **in, t_llist **out, char c)
{
	t_llist	*list;

	list = malloc(sizeof(t_llist));
	if (list == NULL)
		err_mes("Malloc error");
	list->content = (*out)->content;
	list->index = (*out)->index;
	list->next = *in;
	list->prev = NULL;
	(*in)->prev = list;
	*in = list;
	list = *out;
	*out = (*out)->next;
	(*out)->prev = NULL;
	free(list);
	if (c == 'a')
		ft_printf("pa\n");
	else if (c == 'b')
		ft_printf("pb\n");
}

void	ra(t_llist *list, char c)
{
	t_llist	*t;
	int		tmp;
	int		tmp_i;

	t = list;
	tmp = list->content;
	tmp_i = list->index;
	while (list->next)
	{
		list->content = list->next->content;
		list->index = list->next->index;
		list = list->next;
	}
	list->content = tmp;
	list->index = tmp_i;
	list = t;
	if (c == 'a')
		ft_printf("ra\n");
	else if (c == 'b')
		ft_printf("rb\n");
}

void	rr(t_llist *a, t_llist *b)
{
	ra(a, 0);
	ra(b, 0);
}
