/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykostan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:18:26 by lykostan          #+#    #+#             */
/*   Updated: 2023/03/31 17:18:28 by lykostan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <libft.h>
# include <ft_printf.h>

typedef struct s_llist
{
	int	index;
	int				content;
	struct s_llist	*next;
	struct s_llist	*prev;
}	t_llist;

int		*parse(int argc, char **argv, int *len);
void	err_mes(char *s);
int		split_size(char **split);
void	split_free(char **split);
void	merge_sorted(int *args, int start, int mid, int end);
void	merge(int *args, int start, int end);
t_llist	*list_creat(int *args, int len, char c);
void	indexing(t_llist *a, int *args, int len);
void	sa(t_llist *list, char c);
void	ss(t_llist *a, t_llist *b);
void	pa(t_llist **in, t_llist **out, char c);
void	ra(t_llist *list, char c);
void	rr(t_llist *a, t_llist *b);
void	rra(t_llist *list, char c);
void	rrr(t_llist *a, t_llist *b);

#endif
