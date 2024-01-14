/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:17:22 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/11/27 09:12:06 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

t_stack	*get_target(t_stack **a, int val)
{
	t_stack	*target;
	t_stack	*curr;
	int		min;

	curr = *a;
	min = INT_MAX;
	target = NULL;
	while (curr)
	{
		if (curr->val < min && val < curr->val)
		{
			min = curr->val;
			target = curr;
		}
		curr = curr->next;
	}
	if (!target)
		target = get_smallest(a);
	return (target);
}

void	set_target(t_stack	**a, t_stack **b)
{
	t_stack	*target;
	t_stack	*curr_b;

	if (!a || !*a || !b || !*b)
		return ;
	curr_b = *b;
	stack_size(a);
	stack_size(b);
	target = get_target(a, curr_b->val);
	while (curr_b)
	{
		curr_b->target = target->index;
		curr_b->t_val = target->val;
		curr_b = curr_b->next;
		if (curr_b)
			target = get_target(a, curr_b->val);
	}
}

void	calculate_moves_helper(t_stack *curr, int size_a, int size_b)
{
	int	mid_a;
	int	mid_b;

	mid_a = size_a / 2;
	mid_b = size_b / 2;
	curr->type = 999;
	if ((curr->index <= mid_b && curr->target <= mid_a)
		|| (curr->index > mid_b && curr->target <= mid_a
			&& curr->target >= curr->index)
		|| (curr->index <= mid_b && curr->target > mid_a
			&& curr->target <= curr->index))
	{
		curr->type = 0;
		curr->moves = max(curr->index, curr->target);
	}
	else if (curr->index > mid_b && curr->target > mid_a)
	{
		curr->type = 1;
		curr->moves = max(size_b - curr->index, size_a - curr->target);
	}
	else if (curr->index <= mid_b && curr->target > mid_a)
		curr->moves = curr->index + size_a - curr->target;
	else if (curr->index > mid_b && curr->target <= mid_a)
		curr->moves = size_b - curr->index + curr->target;
}
