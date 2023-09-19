/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:14:52 by seoson            #+#    #+#             */
/*   Updated: 2023/09/14 18:29:54 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				data;
	int				index;
	int				stack_a_cnt;
	int				stack_b_cnt;
	int				stack_total_cnt;
	struct s_list	*next;
}	t_list;

t_list		*ft_lstnew(int data);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **list, int data);
void		ft_lstclear(t_list **lst);
int			ft_isnum(char *argv);
int			ft_is_asc(t_list **stack_a);
int			ft_is_desc(t_list **stack_a);
int			ft_atoi(char *argv);
long long	ft_atoi2(char *nptr);
char		**ft_split(char const *s, char c);
int			ft_stack_size(t_list *stack_a);
int			ft_abs(int number);
void		ft_sort_desc(t_list **stack_a, t_list **stack_b);
void		ft_check_dup(t_list **stack_a);
void		ft_check_sort(t_list **stack_a);
int			ft_check_int(long long argv);
void		ft_make_index(t_list **stack_a);
void		ft_count_command_b(t_list **stack_b);
void		ft_count_command_a(t_list **stack_a, t_list **stack_b);
void		push_swap_parsing(int argc, char *argv[], t_list **stack_a);
void		sa(t_list **head, int flag);
void		sb(t_list **head, int flag);
void		ss(t_list **stack_a, t_list **stack_b);
void		pb(t_list **stack_a, t_list **stack_b);
void		pa(t_list **stack_a, t_list **stack_b);
void		ra(t_list **head, int flag);
void		rb(t_list **head, int flag);
void		rr(t_list **stack_a, t_list **stack_b);
void		rra(t_list **head, int flag);
void		rrb(t_list **head, int flag);
void		rrr(t_list **stack_a, t_list **stack_b);
void		sort(t_list **stack_a, t_list **stack_b);
void		sort_over_3(t_list **stack_a, t_list **stack_b);
void		greedy_sort(t_list **stack_a, t_list **stack_b);

#endif
