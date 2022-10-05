/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_args_utils_bonus2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:13:46 by sperez-p          #+#    #+#             */
/*   Updated: 2022/10/05 10:14:08 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap_bonus.h"

int	ft_isdigit(int c)
{
	return ((c >= 48 && c <= 57) || c == 45);
}

int	ft_digit_str(char *str)
{
	while (ft_isdigit(*str) && *str)
		str++;
	return (!*str);
}

void	ft_check_sorted_a(t_checker *checker)
{
	t_stack	*last;
	t_stack	*tmp;

	last = checker->stack_a->prev;
	tmp = checker->stack_a;
	if (tmp != tmp->next)
	{
		while (tmp->nbr < tmp->next->nbr && tmp != last)
			tmp = tmp->next;
		if (tmp != last)
			return ;
	}
	ft_general_free(checker);
	exit (1);
}
