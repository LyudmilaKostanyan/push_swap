/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykostan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:18:07 by lykostan          #+#    #+#             */
/*   Updated: 2023/03/31 17:18:09 by lykostan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int long	num_creat(const char *str, long *k)
{
	int		i;
	int		m;

	i = 0;
	m = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43)
		i++;
	else if (str[i] == 45)
	{
		m++;
		i++;
	}
	while (str[i] == 48)
		i++;
	if (ft_strlen(str + i) > 10)
		err_mes("Too long arg");
	while (str[i] >= 48 && str[i] <= 57)
	{
		*k = *k * 10 + (str[i] - 48);
		i++;
	}
	return (m);
}

int	*ft_atol(char **split, int *len)
{
	long	k;
	int		m;
	int		*args;

	args = (int *)malloc(sizeof(int) * split_size(split));
	if (args == NULL)
		err_mes("Malloc error");
	while (*split)
	{
		k = 0;
		m = num_creat(*split, &k);
		if ((k > 2147483647 && m == 0) || (k > 2147483648 && m != 0))
			err_mes("Too long arg");
		if (m != 0)
			k = -k;
		args[*len] = (int)k;
		split++;
		(*len)++;
	}
	return (args);
}

int	*stoi(char *s, int *len)
{
	int		i;
	int		s_len;
	char	**split;
	int		*args;

	i = -1;
	s_len = ft_strlen(s);
	while (++i < s_len)
	{
		if (s[i] != '+' && s[i] != '-' && s[i] != '\t'
			&& s[i] != '\n' && s[i] != ' ' && !ft_isdigit(s[i]))
			err_mes("Other simbols");
		else if (s[i] == '\t' || s[i] == '\n')
			s[i] = ' ';
	}
	split = ft_split(s, ' ');
	free(s);
	if (split == NULL)
		err_mes("Malloc error");
	args = ft_atol(split, len);
	split_free(split);
	return (args);
}

int	*parse_args(int argc, char **argv, int *len)
{
	int		i;
	char	*s;
	char	*str;
	int		*args;

	s = "";
	i = 0;
	while (++i < argc)
	{
		str = s;
		s = ft_strjoin(s, argv[i]);
		if (*str)
			free (str);
		str = s;
		s = ft_strjoin(s, " ");
		free(str);
	}
	args = stoi(s, len);
	return (args);
}

int	*parse(int argc, char **argv, int *len)
{
	int	*args;
	int	i;
	int	j;

	args = parse_args(argc, argv, len);
	i = -1;
	while (++i < *len)
	{
		j = -1;
		while (++j < *len)
			if (args[i] == args[j] && i != j)
				err_mes("Identical numbers in args");
	}
	return (args);
}
