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

#include "push_swap.h"

void	err_mes(char *s)
{
	ft_printf("Error: %s\n", s);
	exit(0);
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
