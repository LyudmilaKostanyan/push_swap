/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_3_to_13.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykostan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:57:56 by lykostan          #+#    #+#             */
/*   Updated: 2023/04/03 20:57:59 by lykostan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check(t_llist *a)
{
	t_llist	*tmp;

	tmp = a;
	a = a->next;
	while (a)
	{
		if (a->content < a->prev->content)
		{
			a = tmp;
			return (0);
		}
		a = a->next;
	}
	a = tmp;
	return (1);
}

void	for_3(t_llist *a)
{
	if (a->content < a->next->next->content)
	{
		if (a->next->content > a->next->next->content)
		{
			ps_rrotate(a, 'a');
			ps_swap(a, 'a');
		}
		else if (a->content > a->next->content)
			ps_swap(a, 'a');
	}
	else
	{
		if (a->content < a->next->content)
			ps_rrotate(a, 'a');
		else if (a->next->content < a->next->next->content)
			ps_rotate(a, 'a');
		else
		{
			ps_swap(a, 'a');
			ps_rrotate(a, 'a');
		}
	}
}

void	for_less_13(t_llist **a, t_llist **b, int i, int len_stat)
{
	int		tmp;
	t_llist	*tmp_l;

	tmp_l = *a;
	while (*a)
	{
		if ((*a)->index == i)
		{
			tmp = (*a)->content;
			if (i < len_stat / 2)
				while (tmp != tmp_l->content)
					ps_rotate(tmp_l, 'a');
			else
				while (tmp != tmp_l->content)
					ps_rrotate(tmp_l, 'a');
			ps_push(b, &tmp_l, 'b');
			break ;
		}
		*a = (*a)->next;
	}
	*a = tmp_l;
}

void	less_13(t_llist *a, t_llist *b, int len)
{
	int		i;
	int		len_stat;

	i = 0;
	len_stat = len;
	while (len > 3)
	{
		for_less_13(&a, &b, i, len_stat);
		len--;
		i++;
	}
	for_3(a);
	while (len != len_stat)
	{
		ps_push(&a, &b, 'a');
		len++;
	}
}
