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
	return (i);
}

int	lstsize(t_llist *b)
{
	int	i;

	i = 0;
	while (b)
	{
		i++;
		b = b->next;
	}
	return (i);
}

void	f(int i, int max, t_llist *b)
{
	if (i < lstsize(b) / 2)
		while (max != b->content)
			ps_rotate(b, 'b');
	else
		while (max != b->content)
			ps_rrotate(b, 'b');
}

void	end(t_llist *b, int len, int * args, int i)
{
	int		max;
	int	j;
	t_llist	*tmp;

	j = 0;
	indexing(b, args, len);
	tmp = b;
	while (b->index != i)
	{
		j++;
		b = b->next;
	}
	max = b->content;
	b = tmp;
	f(j, max, b);
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
			ps_push(&b, &a, 'b');
			ps_rotate(b, 'b');
			i++;
		}
		else if (a->index <= i + opt)
		{
			ps_push(&b, &a, 'b');
			i++;
		}
		else
			ps_rotate(a, 'a');
	}
	i = len - 1;
	while (b)
	{
		end(b, len, args, i);
		ps_push(&a, &b, 'a');
		i--;
	}
}

void	bubble(int *args, int len)
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (args[j + 1] < args[j])
			{
				tmp = args[j];
				args[j] = args[j + 1];
				args[j + 1] = tmp;
			}
			j++;
		}
		i++;
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
	a = list_creat(args, len, 'a');
	b = NULL;
	bubble(args, len);
	// merge(args, 0, len - 1);
	indexing(a, args, len);
	if (len < 2 || check(a))
		return (0);
	else if (len == 2)
	{
		if (a->content > a->next->content)
			ps_swap(a, 'a');
	}
	else if (len == 3)
		for_3(a);
	else if (len < 13)
		less_13(a, b, len);
	else
		butterfly(a, b, len, args);
	free(args); //need free list a;
	// system("leaks push_swap");
	return (0);
}
