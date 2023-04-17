/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykostan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:18:14 by lykostan          #+#    #+#             */
/*   Updated: 2023/03/31 17:18:15 by lykostan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	err_mes(int condition)
{
	if (condition)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
}

int	split_size(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		;
	return (i);
}

void	split_free(char **split)
{
	int	i;

	i = split_size(split) - 1;
	while (i > -1)
	{
		free(split[i]);
		i--;
	}
	free(split);
	split = NULL;
}

void	free_list(t_llist **list, int *args)
{
	if (!*list)
		return ;
	while ((*list)->next)
	{
		(*list) = (*list)->next;
		free((*list)->prev);
	}
	free(*list);
	free(args);
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
