/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 03:02:50 by marvin            #+#    #+#             */
/*   Updated: 2023/10/15 03:02:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(stack **a)
{
	stack	*bigger;

	bigger = get_bigger(a);
	if (bigger == *a)
		ra(a);
	else if (bigger == (*a)->next)
		rra(a);
	if ((*a)->val > (*a)->next->val)
		sa(a);
}

void	sort_algo(stack **a, stack **b)
{
	size_t	len;
	size_t	size;

	len = stack_len(*a);
	size = len;
	pb(b, a);
	len--;
	if (len <= 5)
	{
		len--;
		pb(b, a);
	}
	while (len > 3)
	{
		target_node(a, b);
		stack *swap_node = find_cheapest(*a);
		while (swap_node->index != 0 || swap_node->target_node->index != 0)
		{
		target_node(a, b);

			if (swap_node->above_median && swap_node->target_node->above_median && swap_node->index != 0 && swap_node->target_node->index != 0)
			{
				rr(a,b);
			}
			else if (swap_node->above_median && swap_node->index != 0)
			{
				ra(a);
			}
			else if (swap_node->target_node->above_median && swap_node->target_node->index != 0)
			{
				rb(b);
			}
			else if (swap_node->above_median == false && swap_node->target_node->above_median == false && swap_node->index != 0 && swap_node->target_node->index != 0)
			{
				rrr(a,b);
			}
			else if (swap_node->above_median == false && swap_node->index != 0)
			{
				rra(a);
			}
			else if (swap_node->target_node->above_median == false && swap_node->target_node->index != 0)
			{
				rrb(b);
			}

		}
		pb(b, a);
		// if ((*b)->val < (*b)->next->val)
		// 	rb(b);

		len--;
	}
	sort_three(a);

	while (*b != NULL)
	{
		target_node2(a, b);
		stack *swap_node = find_cheapest(*b);
		while (swap_node->index != 0 || swap_node->target_node->index != 0)
		{
			if (swap_node->above_median && swap_node->target_node->above_median && swap_node->index && swap_node->target_node->index)
			{
				rr(a, b);
			}
			else if (swap_node->above_median == false && swap_node->target_node->above_median == false && swap_node->index && swap_node->target_node->index)
			{
				rrr(a, b);
			}
			else if (swap_node->above_median && swap_node->index)
			{
				rb(b);
			}
			else if (swap_node->target_node->above_median && swap_node->target_node->index)
			{
				ra(a);
			}
			else if (swap_node->above_median == false && swap_node->index)
			{
				rrb(b);
			}
			else if (swap_node->target_node->above_median == false && swap_node->target_node->index)
			{
				rra(a);
			}
			if (swap_node->target_node->index == stack_len(*b))
				swap_node->target_node->index = 0;
			if (swap_node->index == stack_len(*a))
				swap_node->index = 0;
			target_node2(a, b);
			// sleep(3);
		}
		pa(a, b);
		// if ((*a)->val > (*a)->next->val)

	}
	stack *small = get_bigger(a);
	size_t loop = small->index + 1;
	if (small->above_median)
		while (loop)
		{
			ra(a);
			loop--;
		}
	else
		while (loop < size)
		{
			rra(a);
			loop++;
		}
}

