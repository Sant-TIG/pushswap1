/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input_utils_bonus2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:06:57 by sperez-p          #+#    #+#             */
/*   Updated: 2022/10/05 10:07:13 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap_bonus.h"

void	ft_check_pa(t_checker *checker)
{
	if (checker->stackb_len >= 0)
	{
		if (ft_dlstcmp(checker->read_utils->str, "pa") != 0)
		{
			if (checker->stackb_len == 0)
				ft_error_exit(checker);
			ft_push_a(&checker->stack_a, &checker->stack_b, &checker);
		}
	}
}

void	ft_check_pb(t_checker *checker)
{
	if (checker->stacka_len >= 0)
	{
		if (ft_dlstcmp(checker->read_utils->str, "pb") != 0)
		{
			if (checker->stacka_len == 0)
				ft_error_exit(checker);
			ft_push_b(&checker->stack_a, &checker->stack_b, &checker);
		}
	}
}
