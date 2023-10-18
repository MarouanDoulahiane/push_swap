/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:15:34 by marvin            #+#    #+#             */
/*   Updated: 2023/10/14 23:15:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// # include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct stack
{
	size_t			index;
	int				val;
	bool			above_median;
	int				push_cost;
	int				cheapest;
	struct stack	*target_node;
	struct stack	*next;
	// struct stack	*prev;
}	stack;

char	**ft_split(char const *s, char c);
long	ft_atol(char *str);

void	init_stack_a(stack **a, char ***argv, bool for_free);

void	free_error(stack **a, char ***argv, bool for_free);
void	free_stack(stack **a);
void	free_argv(char ***argv);

stack	*find_last(stack *a);
void	append_node(stack **a, int val);
bool	stack_sorted(stack *a);
size_t	stack_len(stack *a);

void	swap(stack **root);
void	sa(stack **a);
void	sb(stack **b);

void	push(stack **first, stack **second);
void	pa(stack **a, stack **b);
void	pb(stack **b, stack **a);

void	rotate(stack **root);
void	ra(stack **a);
void	rb(stack **b);
void	rr(stack **a, stack **b);

void	reverse(stack **root);
void	rra(stack **a);
void	rrb(stack **b);
void	rrr(stack **a, stack **b);

stack	*get_bigger(stack **a);

bool	error_duplicate(stack *a, int n);
bool	error_syntax(char *str);

void	sort_three(stack **a);
void	sort_algo(stack **a, stack **b);

void	target_node2(stack **a, stack **b);


void	print_stack(stack *a);


int		max(int a, int b);

void	target_node(stack **a, stack **b);
stack	*find_cheapest(stack *a);

#endif