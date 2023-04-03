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

//nrom
t_llist	*list_creat(int *args, int len, char c)
{
	int		i;
	t_llist	*head;
	t_llist	*list;

	i = -1;
	head = malloc(sizeof(t_llist));
	list = head;
	if (head == NULL)
		err_mes("Malloc error");
	while (++i < len)
	{
		if (i == 0)
			head->prev = NULL;
		if (c == 'a')
			head->content = args[i];
		if (i == len - 1)
			head->next = NULL;
		else
		{
			head->next = malloc(sizeof(t_llist));
			if (head == NULL)
				err_mes("Malloc error");
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

void	ps_rrotate(t_llist *list, char c)
{
	int	tmp;
	int	tmp_i;

	while (list->next)
		list = list->next;
	tmp = list->content;
	tmp_i = list->index;
	while (list->prev)
	{
		list->content = list->prev->content;
		list->index = list->prev->index;
		list = list->prev;
	}
	list->content = tmp;
	list->index = tmp_i;
	if (c == 'a')
		ft_printf("rra\n");
	else if (c == 'b')
		ft_printf("rrb\n");
}

void	rrr(t_llist *a, t_llist *b)
{
	ps_rrotate(a, 0);
	ps_rrotate(b, 0);
}
