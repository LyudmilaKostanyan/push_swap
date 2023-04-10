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

void	merge_fill_arr(int *args, t_merg_vars vars)
{
	vars.i = 0;
	vars.j = 0;
	while (vars.i < vars.l_len && vars.j < vars.r_len)
	{
		if (vars.l[vars.i] < vars.r[vars.j])
			args[vars.k++] = vars.l[vars.i++];
		else
			args[vars.k++] = vars.r[vars.j++];
	}
	while (vars.i < vars.l_len)
		args[vars.k++] = vars.l[vars.i++];
	while (vars.j < vars.r_len)
		args[vars.k++] = vars.r[vars.j++];
	free(vars.l);
	free(vars.r);
}

void	merge_sorted(int *args, int start, int mid, int end)
{
	t_merg_vars	vars;

	vars.l_len = mid - start + 1;
	vars.r_len = end - mid;
	vars.l = (int *)malloc(sizeof(int) * vars.l_len);
	vars.r = (int *)malloc(sizeof(int) * vars.r_len);
	vars.i = -1;
	vars.j = -1;
	vars.k = start;
	while (++vars.i < vars.l_len)
		vars.l[vars.i] = args[start + vars.i];
	while (++vars.j < vars.r_len)
		vars.r[vars.j] = args[mid + vars.j + 1];
	vars.k = start;
	merge_fill_arr(args, vars);
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
