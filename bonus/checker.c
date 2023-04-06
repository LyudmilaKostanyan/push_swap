#include "push_swap_bonus.h"

void	sort(t_llist **a, t_llist **b)
{
	char	*s;
	int		len;

	while (1)
	{
		s = get_next_line(0);
		if (!s)
		{
			free(s);
			break ;
		}
		len = ft_strlen(s);
		if (!ft_strncmp(s, "sa\n", len))
			ps_swap(*a);
		else if (!ft_strncmp(s, "sb\n", len))
			ps_swap(*b);
		else if (!ft_strncmp(s, "ss\n", len))
			ss(*a, *b);
		else if (!ft_strncmp(s, "pa\n", len))
			ps_push(a, b);
		else if (!ft_strncmp(s, "pb\n", len))
			ps_push(b, a);
		else if (!ft_strncmp(s, "ra\n", len))
			ps_rotate(a);
		else if (!ft_strncmp(s, "rb\n", len))
			ps_rotate(b);
		else if (!ft_strncmp(s, "rr\n", len))
			rr(a, b);
		else if (!ft_strncmp(s, "rra\n", len))
			ps_rrotate(a);
		else if (!ft_strncmp(s, "rrb\n", len))
			ps_rrotate(b);
		else if (!ft_strncmp(s, "rrr\n", len))
			rrr(a, b);
		else
		{
			write(1, "Error\n", 6);
			exit(0);
		}
		free(s);
	}
}

int	main(int argc, char **argv)
{
	t_llist	*a;
	t_llist	*b;
	int		*args;
	int		len;

	len = 0;
	args = parse(argc, argv, &len);
	if (!len)
		return (0);
	a = list_creat(args, len);
	b = NULL;
	sort(&a, &b);
	if(a && check(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}