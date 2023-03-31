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

int long	at(const char *str, long *k)
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

int	*ft_atol(char **split)
{
	int		j;
	long	k;
	int		m;
	int		*args;

	args = (int *)malloc(sizeof(int) * split_size(split));
	if (args == NULL)
		err_mes("Malloc error");
	j = 0;
	while (*split)
	{
		k = 0;
		m = at(*split, &k);
		if ((k > 2147483647 && m == 0) || (k > 2147483648 && m != 0))
			err_mes("Too long arg");
		if (m != 0)
			k = -k;
		args[j] = (int)k;
		split++;
		j++;
	}
	return (args);
}

char	*parse_args(int argc, char **argv)
{
	int		i;
	char	*s;
	char	*str;
	int		len;

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
	i = -1;
	len = ft_strlen(s);
	while (++i < len)
	{
		if (s[i] != '+' && s[i] != '-' && s[i] != '\t'
			&& s[i] != '\n' && s[i] != ' ' && !ft_isdigit(s[i]))
			err_mes("Other simbols");
		else if (s[i] == '\t' || s[i] == '\n')
			s[i] = ' ';
	}
	return (s);
}

int	*parse(int argc, char **argv)
{
	char	*s;
	char	**split;
	int		*args;

	if (argc == 1)
		err_mes("Args error");
	s = parse_args(argc, argv);
	split = ft_split(s, ' ');
	free(s);
	if (split == NULL)
		err_mes("Malloc error");
	args = ft_atol(split);
	split_free(split);
	int	i;
	int	j;

	i = -1;
	while (++i < argc - 1)
	{
		j = -1;
		while (++j < argc - 1)
			if (args[i] == args[j] && i != j)
				err_mes("Identical numbers in args");
	}
	return (args);
}
