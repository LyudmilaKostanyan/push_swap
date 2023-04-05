/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykostan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 21:00:20 by lykostan          #+#    #+#             */
/*   Updated: 2023/04/03 21:00:24 by lykostan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_sorted(int *args, int start, int mid, int end)
{
	int	i;
	int	j;
	int	k;
	int	*tmp;

	tmp = (int *)malloc(sizeof(int) * end + 1);
	err_mes("Malloc error", tmp == NULL);
	i = start;
	k = start;
	j = mid + 1;
	while (i <= mid && j <= end)
		if (args[i] < args[j])
			tmp[k++] = args[i++];
	else
		tmp[k++] = args[j++];
	while (i <= mid)
		tmp[k++] = args[i++];
	while (j <= end)
		tmp[k++] = args[j++];
	k = start - 1;
	while (++k <= end)
		args[k] = tmp[k];
	free(tmp);
}

void	merge(int *args, int start, int end)
{
	int	mid;

	if (start < end)
	{
		mid = (start + end) / 2;
		merge(args, start, mid);
		merge(args, mid + 1, end);
		merge_sorted(args, start, mid, end);
	}
}
