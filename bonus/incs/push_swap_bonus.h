#ifndef PUSH_SWAP_BONUS_H

# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack //doubly circular linked list to store data in stacks
{
	int				nbr;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_dlstr //doubly linked string
{
	char	c;
	struct s_dlstr	*next;
	struct s_dlstr	*prev;
}	t_dlstr;

typedef struct s_read
{
	t_dlstr	*str;
	t_dlstr	*tmp;
	char	c;
	int		fd;
	char	*tmp_map;
}	t_read;

typedef struct s_checker
{
	t_read	*read_utils;
	t_stack	*stack_a;
	t_stack	*stack_b;

	char	**args;

	size_t	stacka_len;
	size_t	stackb_len;
}	t_checker;

/* TREAT ARGS UTILS FUNCTIONS */

void	ft_treat_args(int argc, char **argv, t_checker *checker);
void	ft_check_sorted_a(t_checker *checker);
char	**ft_split_checker(const char *str, char c, t_checker *checker);
char	**ft_2dstrdup_checker(char **str, t_checker *checker);
size_t	ft_strlen(const char *str);
size_t	ft_2dstrlen(char **str);
int		ft_digit_str(char *str);
int		ft_isdigit(int c);
int		ft_atoi_checker(const char *str, t_checker *checker);

/* GET INPUT UTILS FUNCTIONS */

void	ft_get_input(t_checker *checker);
void	ft_insert_end_char(char c, t_dlstr **str, t_checker *checker);
int		ft_dlstcmp(t_dlstr *dlstr, char *str);
int		ft_dlstcmp(t_dlstr *dlstr, char *str);
int		ft_check_sorted(t_stack *stack_a);

/* MOVEMENTS FUNCTIONS */

void	ft_rotate_a(t_stack **stack_a);
void	ft_rotate_b(t_stack **stack_b);
void	ft_rotate_ab(t_stack **stack_a, t_stack **stack_b);
void	ft_reverse_rotate_a(t_stack **stack_a);
void	ft_reverse_rotate_b(t_stack **stack_b);
void	ft_reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b);
void	ft_swap_a(t_stack **stack_a);
void	ft_swap_b(t_stack **stack_b);
void	ft_swap_ab(t_stack **stack_a, t_stack **stack_b);
void	ft_push_a(t_stack **stack_a, t_stack **stack_b, t_checker **checker);
void	ft_push_b(t_stack **stack_a, t_stack **stack_b, t_checker **checker);

/* LINKED UTILS FUNCTIONS */

void	ft_insert_empty_checker(int nbr, t_stack **stack, t_checker *checker);
void	ft_insert_end_checker(int nbr, t_stack **stack, t_checker *checker);
void	ft_insert_begin_checker(int nbr, t_stack **stack, t_checker *checker);
int		ft_listlen(t_stack *stack_a);

/* PRINT FUNCTIONS */

void	ft_print(char **arg);
void	ft_print_list(t_stack *stack);
void ft_print_list2(t_dlstr *str);

/* FREE FUNCTIONS */

void	ft_general_free(t_checker *checker);
void	ft_free_stack_dlist(t_stack **stack);
void	ft_free_char_dlist(t_dlstr **dlstr);
void	ft_free_2dstr(char **str);

/* ERROR FUNCTIONS */

void	ft_error_exit(t_checker *checker);

#endif