/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykostan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:17:51 by lykostan          #+#    #+#             */
/*   Updated: 2023/03/31 17:17:52 by lykostan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	for_3(t_llist *a)
{
	if (a->content < a->next->next->content)
	{
		if (a->next->content > a->next->next->content)
		{
			rra(a, 'a');
			sa(a, 'a');
		}
		else if (a->content > a->next->content)
			sa(a, 'a');
	}
	else
	{
		if (a->content < a->next->content)
			rra(a, 'a');
		else if(a->next->content < a->next->next->content)
			ra(a, 'a');
		else
		{
			sa(a, 'a');
			rra(a, 'a');
		}
	}
}

void	normal(t_llist **head)
{
	t_llist	*tmp;

	tmp = head;
	while (tmp)
	{
		if ()
	}
}

void	for_less_13(t_llist *a, t_llist *b, t_llist *tmp_l, int len_stat)
{
	int	tmp;

	tmp = a->content;
	if (i < len_stat / 2)
		while (tmp != tmp_l->content)
			ra(tmp_l, 'a');
	else
		while (tmp != tmp_l->content)
			rra(tmp_l, 'a');
	pa(&b, &tmp_l, 'b');
}

void	less_13(t_llist *a, t_llist *b, int len)
{
	int		i;
	int		len_stat;
	t_llist	*tmp_l;
	int		tmp;

	i = 0;
	len_stat = len;
	while (len > 3)
	{
		tmp_l = a;
		while (a)
		{
			if (a->index == i)
			{
				tmp = a->content;
				if (i < len_stat / 2)
					while (tmp != tmp_l->content)
						ra(tmp_l, 'a');
				else
					while (tmp != tmp_l->content)
						rra(tmp_l, 'a');
				pa(&b, &tmp_l, 'b');
				break;
			}
			a = a->next;
		}
		a = tmp_l;
		len--;
		i++;
	}
	for_3(a);
	while (len != len_stat)
	{
		pa(&a, &b, 'a');
		len++;
	}
}

int	main(int argc, char **argv)
{
	t_llist	*a;
	t_llist	*b;
	int		*args;
	int		len;

	if (argc < 2)
		return (0);
	len = 0;
	args = parse(argc, argv, &len);
	if (len < 3)
		return (0);
	a = list_creat(args, len, 'a');
	b = list_creat(args, len, 'b');
	if (len == 3)
	{
		for_3(a);
		return (0);
	}
	merge(args, 0, len - 1);
	indexing(a, args, len);
	if (len < 13)
	{
		less_13(a, b, len);
		// b = a;
		return (0);
	}
	// a = b;
	// printf("\n\n\n");
	// rra(a, 'a');
	// while (a)
	// {
	// 	printf("%d\n", a->content);
	// 	a = a->next;
	// }
	free(args);
	system("leaks push_swap");
	return (0);
}
