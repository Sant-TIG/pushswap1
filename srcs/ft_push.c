/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:02:06 by sperez-p          #+#    #+#             */
/*   Updated: 2022/10/05 09:35:57 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap_bonus.h"

void	ft_push_a(t_stack **stack_a, t_stack **stack_b, t_checker **checker)
{
	t_stack	*tmp;
	int		nbr;

	tmp = *stack_b;
	nbr = (*stack_b)->nbr;
	if (*stack_b == (*stack_b)->next)
	{
		free(*stack_b);
		*stack_b = NULL;
	}
	else
	{
		*stack_b = (*stack_b)->next;
		(*stack_b)->prev = tmp->prev;
		tmp->prev->next = (*stack_b);
		free(tmp);
	}
	ft_insert_begin_checker(nbr, stack_a, *checker);
	(*checker)->stacka_len++;
	(*checker)->stackb_len--;
}

void	ft_push_b(t_stack **stack_a, t_stack **stack_b, t_checker **checker)
{
	t_stack	*tmp;
	int		nbr;

	tmp = *stack_a;
	nbr = (*stack_a)->nbr;
	if (*stack_a == (*stack_a)->next)
	{
		free(*stack_a);
		*stack_a = NULL;
	}
	else
	{
		*stack_a = (*stack_a)->next;
		(*stack_a)->prev = tmp->prev;
		tmp->prev->next = (*stack_a);
		free(tmp);
	}
	ft_insert_begin_checker(nbr, stack_b, *checker);
	(*checker)->stacka_len--;
	(*checker)->stackb_len++;
}
