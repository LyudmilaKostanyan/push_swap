/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykostan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:57:08 by lykostan          #+#    #+#             */
/*   Updated: 2023/04/03 20:57:10 by lykostan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	raise(int i, int max, t_llist **b)
{
	if (i < lstsize(*b) / 2)
		while (max != (*b)->content)
			ps_rotate(b, 'b');
	else
		while (max != (*b)->content)
			ps_rrotate(b, 'b');
}

void	push_a(t_llist **b, int len, int *args, int i)
{
	int		max;
	int		j;
	t_llist	*tmp;

	j = 0;
	indexing(*b, args, len);
	tmp = *b;
	while ((*b)->index != i)
	{
		j++;
		*b = (*b)->next;
	}
	max = (*b)->content;
	*b = tmp;
	raise(j, max, b);
}

void	create_butterfly(t_llist **a, t_llist **b, int len)
{
	int	opt;
	int	i;

	i = 0;
	opt = ft_sqrt(len) + ft_log(len) - 1;
	while (i < len)
	{
		if ((*a)->index <= i)
		{
			ps_push(b, a, 'b');
			ps_rotate(b, 'b');
			i++;
		}
		else if ((*a)->index <= i + opt)
		{
			ps_push(b, a, 'b');
			i++;
		}
		else
			ps_rotate(a, 'a');
	}
}

void	butterfly(t_llist **a, t_llist **b, int len, int *args)
{
	int	i;

	create_butterfly(a, b, len);
	i = len - 1;
	while (*b)
	{
		push_a(b, len, args, i--);
		ps_push(a, b, 'a');
	}
}
