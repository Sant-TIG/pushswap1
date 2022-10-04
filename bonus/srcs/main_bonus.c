#include "../incs/push_swap_bonus.h"

void	ft_init_checker(t_checker *checker)
{
	checker->read_utils = (t_read *)malloc(sizeof(t_read));
	if (!checker->read_utils)
		ft_error_exit(checker);
	checker->read_utils->str = NULL;
	checker->read_utils->tmp = NULL;
	checker->read_utils->tmp_map = NULL;
	checker->stack_a = NULL;
	checker->stack_b = NULL;
	checker->args = NULL;
	checker->stacka_len = 0;
	checker->stackb_len = 0;
}

int	main(int argc, char **argv)
{
	t_checker	checker;

	ft_init_checker(&checker);
	if (argc > 1)
	{
		ft_treat_args(argc, argv, &checker);
		ft_get_input(&checker);
	}
	write(1, "Error\n", 6);
	ft_general_free(&checker);
	return (0);
}