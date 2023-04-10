/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykostan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:59:18 by lykostan          #+#    #+#             */
/*   Updated: 2023/04/03 20:59:19 by lykostan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_llist	*list_creat(int *args, int len)
{
	int		i;
	t_llist	*head;
	t_llist	*list;

	i = -1;
	head = malloc(sizeof(t_llist));
	err_mes("Malloc error", head == NULL);
	list = head;
	while (++i < len)
	{
		if (i == 0)
			head->prev = NULL;
		head->content = args[i];
		if (i == len - 1)
			head->next = NULL;
		else
		{
			head->next = malloc(sizeof(t_llist));
			err_mes("Malloc error", head->next == NULL);
			head->next->prev = head;
		}
		head = head->next;
	}
	return (list);
}

void	indexing(t_llist *a, int *args, int len)
{
	int	i;

	while (a)
	{
		i = -1;
		while (++i < len)
			if (args[i] == a->content)
				a->index = i;
		a = a->next;
	}
}

void	ps_swap(t_llist *list, char c)
{
	int	tmp;
	int	tmp_i;

	if (!list)
		return ;
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
	if (!a || !b)
		return ;
	ps_swap(a, 0);
	ps_swap(b, 0);
	ft_printf("ss\n");
}

void	ps_push(t_llist **in, t_llist **out, char c)
{
	t_llist	*tmp;

	if (!*out)
		return ;
	tmp = (*out)->next;
	if (*in)
	{
		(*in)->prev = *out;
		(*out)->next = *in;
	}
	else
		(*out)->next = NULL;
	(*out)->prev = NULL;
	if (tmp)
		tmp->prev = NULL;
	*in = *out;
	*out = tmp;
	if (c == 'a')
		ft_printf("pa\n");
	else if (c == 'b')
		ft_printf("pb\n");
}
