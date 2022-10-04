#include "../incs/push_swap_bonus.h"

void	ft_error_exit(t_checker *checker)
{
	write(1, "Error\n", 6);
	ft_general_free(checker);
	exit (1);
}