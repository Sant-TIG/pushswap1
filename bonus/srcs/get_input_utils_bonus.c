#include "../incs/push_swap_bonus.h"

int	ft_dlstcmp(t_dlstr *dlstr, char *str)
{
	t_dlstr	*tmp;

	if (!dlstr || !str)
		return (0);
	tmp = dlstr;
	while (tmp && *str)
	{
		//printf("%c y %c\n", tmp->c, *str);
		if (tmp->c != *str)
			return (0);
		tmp = tmp->next;
		str++; 
	}
	if (tmp || *str)
		return (0);
	return (1);
}

static void	ft_insert_empty_char(char c, t_dlstr **str, t_checker *checker)
{
	t_dlstr	*new;

	new = (t_dlstr *)malloc(sizeof(t_dlstr));
	if (!new)
		ft_error_exit(checker);
	new->c = c;
	new->next = NULL;
	new->prev = NULL;
	*str = new;
}

void	ft_insert_end_char(char c, t_dlstr **str, t_checker *checker)
{
	t_dlstr	*tmp;
	t_dlstr	*new;

	tmp = *str;
	if (!*str)
	{
		ft_insert_empty_char(c, str, checker);
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	new = (t_dlstr *)malloc(sizeof(t_dlstr));
	if (!new)
		ft_error_exit(checker);
	new->c = c;
	new->next = NULL;
	new->prev = tmp;
	(*str)->prev = new;
	tmp->next = new;
}

int	ft_check_sorted(t_stack *stack_a)
{
	t_stack	*last;
	t_stack	*tmp;

	last = stack_a->prev;
	tmp = stack_a;
	if (tmp != tmp->next)
	{
		while (tmp->nbr < tmp->next->nbr && tmp != last)
			tmp = tmp->next;
		if (tmp != last)
			return (0);
	}
	return (1);
}