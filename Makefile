S = srcs/
O = objs/
B = bonus/

NAME = push_swap
BONUS_NAME = checker

SRCS = $Smain.c\
	   $Serror_exit.c $Sfree.c\
	   $Sft_split_push.c $Slinked_utils.c $Slinked_utils2.c $Streat_args_utils.c $Streat_args_utils2.c\
	   $Sft_swap.c $Sft_rotate.c $Sft_push.c $Sft_reverse_rotate.c\
	   $Streat_args.c $Sft_treat_three_case.c $Sft_sort_a.c $Sft_sort_b.c\
	   $Sprint.c $Sft_quick_sort.c $Scommon_utils.c

SRCS_BONUS = $B$Smain_bonus.c\
			 $B$Streat_args_bonus.c $B$Streat_args_utils_bonus.c $B$Streat_args_utils_bonus2.c\
			 $B$Serror_exit_bonus.c $B$Sfree_bonus.c\
			 $B$Sft_split_checker_bonus.c $B$Slinked_utils_bonus.c\
			 $B$Sget_input_bonus.c $B$Sget_input_utils_bonus.c\
			 $B$Sft_swap.c $B$Sft_rotate.c $B$Sft_push.c $B$Sft_reverse_rotate.c\
			 $B$Sprint.c
	
OBJS = $Omain.o\
	   $Oerror_exit.o $Ofree.o\
	   $Oft_split_push.o $Olinked_utils.o $Olinked_utils2.o $Otreat_args_utils.o $Otreat_args_utils2.o\
	   $Oft_swap.o $Oft_rotate.o $Oft_push.o $Oft_reverse_rotate.o\
	   $Otreat_args.o $Oft_treat_three_case.o $Oft_sort_a.o $Oft_sort_b.o\
	   $Oprint.o $Oft_quick_sort.o $Ocommon_utils.o

OBJS_BONUS = $B$Omain_bonus.o\
			 $B$Otreat_args_bonus.o $B$Otreat_args_utils_bonus.o $B$Otreat_args_utils_bonus2.o\
			 $B$Oget_input_bonus.o $B$Oget_input_utils_bonus.o\
			 $B$Oerror_exit_bonus.o $B$Ofree_bonus.o\
			 $B$Oft_split_checker_bonus.o $B$Olinked_utils_bonus.o\
			 $B$Oft_swap.o $B$Oft_rotate.o $B$Oft_push.o $B$Oft_reverse_rotate.o\
			 $B$Oprint.o

CC = gcc #-fsanitize=address -g3
CFLAGS =  -Wall -Werror -Wextra #-fsanitize=address -g3

RM = -rm -rf

all: $(NAME)

$O:
	@echo "Creating Objects Folder...."
	mkdir $@
	@echo "Folder created."

$(OBJS): | $O

$(OBJS): $O%.o: $S%.c
	$(CC)  -g3 -c $< -o $@

$(NAME): $(OBJS)
	$(CC)  $^ -o $@

bonus: $(BONUS_NAME)

$B$O:
	@echo "Creating Objects Folder...."
	mkdir $@
	@echo "Folder created."

$(OBJS_BONUS): | $B$O

$(OBJS_BONUS): $B$O%.o: $B$S%.c
	$(CC)  -c $< -o $@

$(BONUS_NAME): $(OBJS_BONUS)
	$(CC)  $^ -o $@

clean:
	$(RM) $(OBJS) $(OBJS_BONUS) $O $B$O

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re