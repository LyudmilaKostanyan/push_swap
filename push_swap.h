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
	int				index;
	int				content;
	struct s_llist	*next;
	struct s_llist	*prev;
}	t_llist;

int		*parse(int argc, char **argv, int *len);
void	err_mes(char *s, int condition);
int		split_size(char **split);
void	split_free(char **split);
int		check(t_llist *a);
void	merge_sorted(int *args, int start, int mid, int end);
void	merge(int *args, int start, int end);
t_llist	*list_creat(int *args, int len);
void	indexing(t_llist *a, int *args, int len);
void	ps_swap(t_llist *list, char c);
void	ss(t_llist *a, t_llist *b);
void	ps_push(t_llist **in, t_llist **out, char c);
void	ps_rotate(t_llist **list, char c);
void	rr(t_llist *a, t_llist *b);
void	ps_rrotate(t_llist **list, char c);
void	rrr(t_llist *a, t_llist *b);
void	for_3(t_llist *a);
void	for_less_13(t_llist **a, t_llist **b, int i, int len_stat);
void	less_13(t_llist *a, t_llist *b, int len);
int		ft_sqrt(int nb);
int		ft_log(int nb);
int		lstsize(t_llist *b);
void	raise(int i, int max, t_llist **b);
void	push_a(t_llist **b, int len, int *args, int i);
void	butterfly(t_llist *a, t_llist *b, int len, int *args);
void	free_list(t_llist *list, int *args);

#endif
