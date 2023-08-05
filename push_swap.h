/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongho <seongho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:14:52 by seoson            #+#    #+#             */
/*   Updated: 2023/08/05 17:11:33 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> //제거필요
typedef struct s_list
{
	int		data;
	int		stack_a_cnt;
	int		stack_b_cnt;
	struct s_list	*next;
} t_list;

t_list	*ft_lstnew(int data);
void	ft_lstadd_back(t_list **list, int data);
void	ft_lstclear(t_list **lst);
t_list	*ft_lstlast(t_list *lst);
int		ft_isnum(char *argv);
int		ft_atoi(char *argv);
long long	ft_atoi2(char *nptr);
char	**ft_split(char const *s, char c);
size_t	ft_lst_len(const char *s);
void	sa(t_list **head, int flag);
void	sb(t_list **head, int flag);
void	ss(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	ra(t_list **head, int flag);
void	rb(t_list **head, int flag);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **head, int flag);
void	rrb(t_list **head, int flag);
void	rrr(t_list **stack_a, t_list **stack_b);
void	sort(t_list **stack_a, t_list **stack_b);
int		stack_size(t_list *stack_a);
void	make_index(t_list **stack_a);
void	sort_over_3(t_list **stack_a, t_list **stack_b);
#endif
