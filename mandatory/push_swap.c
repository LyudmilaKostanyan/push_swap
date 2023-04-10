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

void	choose_way(t_llist **a, t_llist **b, int *args, int len)
{
	if (len < 2 || check(*a))
		return ;
	else if (len == 2)
	{
		if ((*a)->content > (*a)->next->content)
			ps_swap(*a, 'a');
	}
	else if (len == 3)
		for_3(a);
	else if (len < 13)
		less_13(a, b, len);
	else
		butterfly(a, b, len, args);
}

int	main(int argc, char **argv)
{
	t_llist	*a;
	t_llist	*b;
	int		*args;
	int		len;

	b = NULL;
	if (argc < 2)
		return (0);
	len = 0;
	args = parse(argc, argv, &len);
	a = list_creat(args, len);
	if (!len)
	{
		free(args);
		return (0);
	}
	merge(args, 0, len - 1);
	indexing(a, args, len);
	choose_way(&a, &b, args, len);
	free_list(&a, args);
	return (0);
}
