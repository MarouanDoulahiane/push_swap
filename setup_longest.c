/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_longest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 05:30:56 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/11/30 22:11:29 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	set_flags_helper(t_stack **a, int sub_index)
{
	t_stack	*curr;

	if (sub_index == -1)
		return ;
	curr = *a;
	while (curr)
	{
		if (curr->index == sub_index)
		{
			curr->flag = 1;
			set_flags_helper(a, curr->sub_index);
			break ;
		}
		curr = curr->next;
	}
}

void	set_flags(t_stack **a)
{
	t_stack	*curr;
	int		max_lenght;

	max_lenght = get_max_lenght(*a);
	curr = *a;
	while (curr)
	{
		if (curr->lenght == max_lenght)
		{
			curr->flag = 1;
			set_flags_helper(a, curr->sub_index);
			break ;
		}
		curr = curr->next;
	}
}

void	set_smallest_at_top(t_stack **a)
{
	t_stack	*smaller;
	int		size;

	size = stack_size(a);
	smaller = get_smallest(a);
	while (smaller && (smaller->index && smaller->index < size))
	{
		if (smaller->index <= size / 2)
		{
			ra(a);
			smaller->index--;
		}
		else
		{
			rra(a);
			smaller->index++;
		}
	}
	stack_size(a);
}

void	setup_longest_helper(t_stack **stack_j, t_stack **stack_i, t_stack **a)
{
	while ((*stack_j)->val != (*stack_i)->val)
	{
		if ((*stack_j)->val < (*stack_i)->val
			&& (*stack_i)->lenght < (*stack_j)->lenght + 1)
		{
			(*stack_i)->lenght = (*stack_j)->lenght + 1;
			(*stack_i)->sub_index = (*stack_j)->index;
		}
		if (!(*stack_j)->next)
			*stack_j = *a;
		else
			*stack_j = (*stack_j)->next;
	}
}

void	setup_longest(t_stack **a)
{
	t_stack	*stack_i;
	t_stack	*stack_j;
	t_stack	*reminder;
	t_stack	*smaller;
	bool	try;

	smaller = get_smallest(a);
	stack_i = smaller->next;
	if (!stack_i)
		stack_i = (*a);
	reminder = stack_i;
	try = true;
	while (try || stack_i->val != reminder->val)
	{
		try = false;
		stack_j = smaller;
		setup_longest_helper(&stack_j, &stack_i, a);
		if (!stack_i->next)
			stack_i = *a;
		else
			stack_i = stack_i->next;
	}
	set_flags(a);
}
