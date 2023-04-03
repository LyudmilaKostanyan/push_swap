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

void	bubble(int *args, int len)
{
	int	i;
	int	j;
	int	tmp;

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
