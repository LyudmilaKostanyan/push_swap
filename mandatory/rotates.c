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

void	ps_rotate(t_llist **list, char c)
{
	t_llist	*tmp;
	t_llist	*head;

	if (!*list || !(*list)->next)
		return ;
	head = (*list)->next;
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	(*list)->next->prev = NULL;
	(*list)->next = NULL;
	(*list)->prev = tmp;
	tmp->next = *list;
	*list = head;
	if (c == 'a')
		ft_printf("ra\n");
	else if (c == 'b')
		ft_printf("rb\n");
}

void	rr(t_llist **a, t_llist **b)
{
	ps_rotate(a, 0);
	ps_rotate(b, 0);
	ft_printf("rr\n");
}

void	ps_rrotate(t_llist **list, char c)
{
	t_llist	*tmp;

	if (!*list || !(*list)->next)
		return ;
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	(*list)->prev = tmp;
	tmp->prev->next = NULL;
	tmp->next = *list;
	tmp->prev = NULL;
	*list = tmp;
	if (c == 'a')
		ft_printf("rra\n");
	else if (c == 'b')
		ft_printf("rrb\n");
}

void	rrr(t_llist **a, t_llist **b)
{
	ps_rrotate(a, 0);
	ps_rrotate(b, 0);
	ft_printf("rrr\n");
}
