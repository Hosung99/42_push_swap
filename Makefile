cc = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRCS = push_swap.c ft_isnum.c ft_split.c ft_atoi.c ft_lstadd_back.c ft_lstlast.c ft_lstnew.c ft_lstclear.c push_swap_sa.c push_swap_ss.c push_swap_sb.c push_swap_pb.c push_swap_ra.c push_swap_rb.c push_swap_rr.c push_swap_rra.c push_swap_rrb.c push_swap_rrr.c ft_atoi2.c push_swap_sort.c ft_stack_size.c ft_make_index.c push_swap_sort_over_3.c push_swap_pa.c push_swap_greedy_sort.c ft_check_sort.c ft_check_dup.c ft_count_command_a.c ft_count_command_b.c ft_check_int.c ft_is_desc.c ft_sort_desc.c push_swap_parsing.c ft_is_asc.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re