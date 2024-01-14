/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:50:24 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/11/27 11:47:41 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_stack	*best_move_to_b(t_stack **a)
{
	t_stack	*best;
	t_stack	*curr;
	int		size;
	int		min;

	best = NULL;
	size = stack_size(a);
	curr = *a;
	min = INT_MAX;
	while (curr)
	{
		if (!curr->flag && curr->index <= size / 2)
			curr->moves = curr->index;
		else if (!curr->flag && curr->index > size / 2)
			curr->moves = (size - curr->index);
		if (!curr->flag && abs(curr->moves) < min)
		{
			min = abs(curr->moves);
			best = curr;
		}
		curr = curr->next;
	}
	return (best);
}

void	push_to_b(t_stack **a, t_stack **b)
{
	t_stack	*best;

	setup_longest(a);
	best = best_move_to_b(a);
	while (best)
	{
		while (best->moves > 0)
		{
			ra(a);
			best->moves--;
		}
		while (best->moves < 0)
		{
			rra(a);
			best->moves++;
		}
		pb(b, a);
		best = best_move_to_b(a);
	}
}
