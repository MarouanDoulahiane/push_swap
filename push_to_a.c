/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:17:13 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/11/26 10:51:42 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	calculate_moves(t_stack **a, t_stack **b)
{
	int		size_a;
	int		size_b;
	t_stack	*curr;

	curr = *b;
	size_a = stack_size(a);
	size_b = stack_size(b);
	set_target(a, b);
	while (curr)
	{
		calculate_moves_helper(curr, size_a, size_b);
		curr = curr->next;
	}
}

t_stack	*best_move_to_a(t_stack **a, t_stack **b)
{
	t_stack	*best;
	t_stack	*curr;
	int		min;

	if (!a || !b || !*a || !*b)
		return (NULL);
	min = INT_MAX;
	best = NULL;
	curr = *b;
	stack_size(b);
	calculate_moves(a, b);
	while (curr)
	{
		if (curr->moves < min)
		{
			best = curr;
			min = curr->moves;
		}
		curr = curr->next;
	}
	return (best);
}

void	push_to_a_helper_1(t_stack **a, t_stack **b, t_stack *best)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(a);
	size_b = stack_size(b);
	while (best->type == 0 && best->index && best->target)
	{
		rr(a, b);
		best->index--;
		best->target--;
	}
	while (best->type == 1 && best->index < size_b && best->target < size_a)
	{
		rrr(a, b);
		best->index++;
		best->target++;
	}
}

void	push_to_a_helper_2(t_stack **a, t_stack **b, t_stack *best)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(a);
	size_b = stack_size(b);
	while (best->target <= size_a / 2 && best->target)
	{
		ra(a);
		best->target--;
	}
	while (best->target > size_a / 2 && best->target < size_a)
	{
		rra(a);
		best->target++;
	}
	while (best->index <= size_b / 2 && best->index)
	{
		rb(b);
		best->index--;
	}
	while (best->index > size_b / 2 && best->index < size_b)
	{
		rrb(b);
		best->index++;
	}
}

void	push_to_a(t_stack **a, t_stack **b)
{
	t_stack	*best;
	int		size_a;
	int		size_b;

	if (!a || !*a || !b || !*b)
		return ;
	size_a = stack_size(a);
	size_b = stack_size(b);
	best = best_move_to_a(a, b);
	while (best)
	{
		push_to_a_helper_1(a, b, best);
		push_to_a_helper_2(a, b, best);
		pa(a, b);
		size_a = stack_size(a);
		size_b = stack_size(b);
		best = best_move_to_a(a, b);
	}
}
