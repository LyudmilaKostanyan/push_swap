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

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <libft.h>
# include <ft_printf.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

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
t_llist	*list_creat(int *args, int len);
void	ps_swap(t_llist *list);
void	ss(t_llist *a, t_llist *b);
void	ps_push(t_llist **in, t_llist **out);
void	ps_rotate(t_llist **list);
void	rr(t_llist **a, t_llist **b);
void	ps_rrotate(t_llist **list);
void	rrr(t_llist **a, t_llist **b);
void	free_list(t_llist *list, int *args);
char	*get_next_line(int fd);
int		ft_strchr_gnl(char *str, int c);
char	*ft_strdup_gnl(char *s, int start, int j);
char	*ft_strjoin_gnl(char *s1, char *s2);

#endif
