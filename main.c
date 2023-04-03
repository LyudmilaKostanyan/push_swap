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
		else if (a->next->content < a->next->next->content)
			ra(a, 'a');
		else
		{
			sa(a, 'a');
			rra(a, 'a');
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
					ra(tmp_l, 'a');
			else
				while (tmp != tmp_l->content)
					rra(tmp_l, 'a');
			pa(b, &tmp_l, 'b');
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
		pa(&a, &b, 'a');
		len++;
	}
}

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

int	ft_sqrt(int nb)
{
	int	i;

	i = 3;
	while (i * i < nb)
		i++;
	if (i * i == nb)
		return (i);
	return (i - 1);
}

int	ft_log(int nb)
{
	int	i;

	i = 0;
	while (nb)
	{
		nb /= 2;
		i++;
	}
	return (i - 1);
}

void	end(t_llist *a, t_llist *b, int len, int * args)
{
	int		i;
	int		j;
	t_llist	*tmp_l;;
	int		tmp;

	(void)a;
	indexing(b, args, len);
	tmp_l = b;
	i = len - 1;
	j = 0;
	while (i >= 0)
	{
		if (tmp_l->index == i)
		{
			tmp = tmp_l->content;
			if (j < len / 2)
				while (b->content != tmp)
					ra(b, 'b');
			else
				while (b->content != tmp)
					rra(b, 'b');
			pa(&a, &b, 'a');
			i--;
			tmp_l = b;
		}
		else
		{
			j++;
			tmp_l = tmp_l->next;
		}
	}
	// while (a)
	// {
	// 	printf("%d\n", a->content);
	// 	a = a->next;
	// }
}

void	butterfly(t_llist *a, t_llist *b, int len, int *args)
{
	int	opt;
	int	i;

	i = 0;
	opt = ft_sqrt(len) + ft_log(len) - 1;
	while (i < len)
	{
		if (a->index <= i)
		{
			pa(&b, &a, 'b');
			ra(b, 'b');
			i++;
		}
		else if (a->index <= i + opt)
		{
			pa(&b, &a, 'b');
			i++;
		}
		else
			ra(a, 'a');
	}
	end(a, b, len, args);
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
	a = list_creat(args, len, 'a');
	b = NULL;
	if (len < 3 || check(a))
		return (0);
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
		return (0);
	}
	butterfly(a, b, len, args);
	free(args);
	system("leaks push_swap");
	return (0);
}
