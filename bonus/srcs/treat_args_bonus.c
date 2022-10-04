#include "../incs/push_swap_bonus.h"

static void	ft_check_list(t_checker  *checker)
{
	t_stack		*tmp;
	t_stack		*tmp1;
	size_t		len;
	size_t		len1;

	len = checker->stacka_len;
	tmp = checker->stack_a;
	while (--len)
	{
		len1 = len;
		tmp1 = tmp->next;
		while (len1--)
		{
			if (tmp->nbr == tmp1->nbr && len > 0)
				ft_error_exit(checker);
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
}

static void	ft_check_args(t_checker *checker)
{
	size_t	i;
	char	**tmp;

	i = 0;
	tmp = checker->args;
	while (*(tmp + i) && ft_digit_str(*(tmp + i)))
		i++;
	if (*(tmp + i) != NULL)
		ft_error_exit(checker);
}

void	ft_treat_args(int argc, char **argv, t_checker *checker)
{
	int	i;

	i = -1;
	if (argc == 2)
		checker->args = ft_split_checker(*(argv + 1), ' ', checker);
	else
		checker->args = ft_2dstrdup_checker(argv + 1, checker);
	ft_check_args(checker);
	while (*(checker->args + ++i))
		ft_insert_end_checker(ft_atoi_checker(*(checker->args + i), checker), &checker->stack_a, checker);
	checker->stacka_len = ft_listlen(checker->stack_a);
	ft_check_list(checker);
	ft_check_sorted_a(checker);
}
