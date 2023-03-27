#include "push_swap.h"

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

static long	at(const char *str, int i)
{
	long	k;

	k = 0;
	while (str[i] == 48)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		k = k * 10 + (str[i] - 48);
		i++;
	}
	return (k);
}

int	ft_atol(const char *str)
{
	int		i;
	long	k;
	int		m;

	m = 0;
	k = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43)
		i++;
	else if (str[i] == 45)
	{
		m++;
		i++;
	}
	k = at(str, i);
	if (m != 0)
		return (-k);
	return (k);
}

void	parse(int argc, char **argv)
{
	int		i;
	char	*s;
	char	*str;
	char	**split;
	long	num;

	if (argc < 3)
		exit(0);
	s = "";
	i = 1;
	while (++i < argc)
	{
		str = s;
		s = ft_strjoin(s, argv[i]);
		if (*str)
			free (str);
	}
	i = -1;
	int len = ft_strlen(s);
	while (++i < len)
	{
		if (s[i] != '+' && s[i] != '-' && s[i] != '\t'
			&& s[i] != '\n' && s[i] != ' ' && !ft_isdigit(s[i]))
		{
			write(1, "Error\n", 6);
			free(s);
			exit(0);
		}
	}
	split = ft_split(s, ' ');
	free(s);
	if (split == NULL)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	i = -1;
	while (split[++i])
	{
		if (ft_strlen(split[i]) > 10)
		{
			write(1, "Error\n", 6);
			split_free(split);
			exit(0);
		}
	}
	i = -1;
	while (split[++i])
	{
		num = ft_atol(split[i]);
		if (num > 2147483647 || num < -2147483648)
		{
			write(1, "Error\n", 6);
			split_free(split);
			exit(0);
		}
	}
}