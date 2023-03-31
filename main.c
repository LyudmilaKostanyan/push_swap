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

t_llist	*list_creat(int argc, int *args)
{
	int		i;
	t_llist	*head;
	t_llist	*list;

	i = -1;
	head = malloc(sizeof(t_llist));
	list = head;
	if (head == NULL)
		err_mes("Malloc error");
	while (++i < argc - 1)
	{
		if (i == 0)
			head->prev = NULL;
		head->content = args[i];
		if (i == argc - 2)
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

// void	merge(int *args, int start, int end)
// {
// 	int	mid;

// 	mid = (end - start) / 2;
// 	if (start < end)
// 	{
// 		merge(args, 0, mid);
// 		merge(args, mid + 1, end);
// 	}

// }

int	main(int argc, char **argv)
{
	t_llist	*list;
	int	*args;

	args = parse(argc, argv);
	// merge(args, 0, argc - 1);
	list = list_creat(argc, args);
	free(args);
	// system("leaks push_swap");
	return (0);
}
