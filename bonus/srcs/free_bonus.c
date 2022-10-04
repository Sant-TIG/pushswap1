# include "../incs/push_swap_bonus.h"

void	ft_free_2dstr(char **str)
{
	int	i;

	i = -1;
	while (*(str + ++i))
		free(*(str + i));
	free(str);
}

void	ft_free_char_dlist(t_dlstr **dlstr)
{
	t_dlstr	*tmp;

	tmp = *dlstr;
	while (tmp)
	{
		tmp = tmp->next;
		free(*dlstr);
		*dlstr = tmp;
	}
	free(*dlstr);
	*dlstr = NULL;
}

void	ft_free_stack_dlist(t_stack **stack)
{
	t_stack *last;
	t_stack	*tmp;

	tmp = *stack;
	last = (*stack)->prev;
	while (tmp != last)
	{
		tmp = tmp->next;
		free(*stack);
		*stack = tmp;
	}
	free(*stack);
	*stack = NULL;
}

void	ft_general_free(t_checker *checker)
{
	if (checker->read_utils->str)
		ft_free_char_dlist(&checker->read_utils->str);
	if (checker->read_utils->tmp_map)
		free(checker->read_utils->tmp_map);
	if (checker->read_utils)
		free(checker->read_utils);
	if (checker->args)
		ft_free_2dstr(checker->args);
	if (checker->stack_a)
		ft_free_stack_dlist(&checker->stack_a);
}