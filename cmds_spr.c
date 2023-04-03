/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_spr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykostan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:58:21 by lykostan          #+#    #+#             */
/*   Updated: 2023/04/03 20:58:24 by lykostan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_swap(t_llist *list, char c)
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
	ps_swap(a, 0);
	ps_swap(b, 0);
	ft_printf("ss\n");
}

//norm
void	ps_push(t_llist **in, t_llist **out, char c)
{
	t_llist	*list;

	if (!*out)
		return ;
	list = malloc(sizeof(t_llist));
	if (list == NULL)
		err_mes("Malloc error");
	list->content = (*out)->content;
	list->index = (*out)->index;
	if (*in)
		list->next = *in;
	else
		list->next = NULL;
	list->prev = NULL;
	if (*in)
		(*in)->prev = list;
	*in = list;
	list = *out;
	*out = (*out)->next;
	if (*out)
		(*out)->prev = NULL;
	free(list);
	if (c == 'a')
		ft_printf("pa\n");
	else if (c == 'b')
		ft_printf("pb\n");
}

void	ps_rotate(t_llist *list, char c)
{
	t_llist	*t;
	int		tmp;
	int		tmp_i;

	if (!list || !list->next)
		return ;
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
	ps_rotate(a, 0);
	ps_rotate(b, 0);
}
