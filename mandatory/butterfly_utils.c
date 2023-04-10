/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykostan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:57:33 by lykostan          #+#    #+#             */
/*   Updated: 2023/04/03 20:57:36 by lykostan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int		i;
	t_llist	*tmp;

	i = 0;
	tmp = b;
	while (b)
	{
		i++;
		b = b->next;
	}
	b = tmp;
	return (i);
}
