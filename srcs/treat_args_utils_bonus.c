/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_args_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:11:22 by sperez-p          #+#    #+#             */
/*   Updated: 2022/10/05 10:13:40 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap_bonus.h"

int	ft_atoi_checker(const char *str, t_checker *checker)
{
	long int	result;
	ssize_t		sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
		result = (*str++ - 48) + (result * 10);
	if ((result * sign) < -2147483648 || (result * sign) > 2147483647)
		ft_error_exit(checker);
	return ((int)result * sign);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

size_t	ft_2dstrlen(char **str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

char	**ft_2dstrdup_checker(char **str, t_checker *checker)
{
	char	**dst;
	size_t	len;
	int		i;
	int		j;

	i = -1;
	len = ft_2dstrlen(str);
	dst = (char **)malloc(sizeof(char *) * (len + 1));
	if (!dst)
		ft_error_exit(checker);
	while (*(str + ++i))
	{
		j = -1;
		len = ft_strlen(*(str + i));
		*(dst + i) = (char *)malloc(sizeof(char) * len + 1);
		if (!*(dst + i))
			ft_error_exit(checker);
		while (*(*(str + i) + ++j))
			*(*(dst + i) + j) = *(*(str + i) + j);
		*(*(dst + i) + j) = '\0';
	}
	*(dst + i) = NULL;
	return (dst);
}
