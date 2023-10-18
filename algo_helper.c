/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:17:17 by marvin            #+#    #+#             */
/*   Updated: 2023/10/15 13:17:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_index(stack *root, int val)
{
	size_t	i;

	i = 0;
	while (root)
	{
		if (root->val == val)
			return (i);
		i++;
	}
	return (i);
}

stack	*get_node(stack *root, int val)
{
	size_t	i;

	i = 0;
	while (root)
	{
		if (root->val == val)
			return (root);
		i++;
	}
	return (NULL);
}

stack	*get_bigger(stack **a)
{
	stack	*biggest;
	int	nb;

	nb = INT_MIN;
	stack *curr = *a;
	size_t i = 0;
	while (curr)
	{
		if (curr->val > nb)
		{
			nb = curr->val;
			biggest = curr;
		}
		curr->index = i;
		i++;
		curr = curr->next;
	}
	return (biggest);
}

stack	*get_smaller(stack **a)
{
	stack	*smaller;
	int	nb;

	nb = INT_MAX;
	stack *curr = *a;
	while (curr)
	{
		if (curr->val < nb)
		{
			nb = curr->val;
			smaller = curr;
		}
		curr = curr->next;
	}
	return (smaller);
}


// set `index` & `above median` & `push cust` & `cheapest`
void	target_node(stack **a, stack **b)
{
	stack	*target_node;
	stack	*curr_a;
	stack	*curr_b;
	size_t	len_a;
	size_t	len_b;
	size_t	index;
	size_t	j; // *b index
	int	nb = INT_MIN;


	if (*b == NULL || *a == NULL)
		return ;
	curr_a = *a;
	index = 0;
	len_a = stack_len(curr_a);
	len_b = stack_len(*b);
	while (curr_a)
	{
		curr_b = *b;
		j = 0;
		while (curr_b)
		{
			curr_b->index = j;
			if (j <= len_b / 2)
			{
				curr_b->above_median = true;
				curr_b->push_cost = j;
			}
			else
			{
				curr_b->above_median = false;
				curr_b->push_cost = len_b - j;
			}

			if (curr_a->val > curr_b->val && curr_b->val > nb)
			{
				nb = curr_b->val;
				target_node = curr_b;
			}
			curr_b = curr_b->next;
			j++;
		}

		if (nb == INT_MIN)
			target_node = get_bigger(b);
		curr_a->target_node = target_node;
		curr_a->target_node->target_node = curr_a;
		curr_a->index = index;
		if (index <= len_a / 2)
		{
			curr_a->above_median = true;
			curr_a->push_cost = index;
		}
		else
		{
			curr_a->above_median = false;
			curr_a->push_cost = len_a - index;
		}
		if (curr_a->above_median == curr_a->target_node->above_median)
			curr_a->cheapest = max(curr_a->push_cost, curr_a->target_node->push_cost);
		else
			curr_a->cheapest = curr_a->push_cost + curr_a->target_node->push_cost;
		curr_a = curr_a->next;
		index++;
	}
}

void	target_node2(stack **a, stack **b)
{
	stack	*target_node;
	stack	*curr_a;
	stack	*curr_b;
	size_t	len_a;
	size_t	len_b;
	size_t	index;
	size_t	j; // *b index
	int	nb = INT_MAX;


	if (*b == NULL || *a == NULL)
		return ;
	index = 0;
	len_b = stack_len(*a);
	len_a = stack_len(*b);
	curr_b = *b;
	while (curr_b)
	{
		curr_a = *a;
		j = 0;
		while (curr_a)
		{
			curr_a->index = j;
			if (j <= len_b / 2)
			{
				curr_a->above_median = true;
				curr_a->push_cost = j;
			}
			else
			{
				curr_a->above_median = false;
				curr_a->push_cost = len_b - j;
			}

			if (curr_b->val < curr_a->val && curr_a->val < nb)
			{
				nb = curr_a->val;
				target_node = curr_a;
			}
			curr_a = curr_a->next;
			j++;
		}

		if (nb == INT_MAX)
			target_node = get_smaller(a);
		curr_b->target_node = target_node;
		curr_b->target_node->target_node = curr_b;
		curr_b->index = index;
		if (index <= len_a / 2)
		{
			curr_b->above_median = true;
			curr_b->push_cost = index;
		}
		else
		{
			curr_b->above_median = false;
			curr_b->push_cost = len_a - index;
		}
		if (curr_b->above_median == curr_b->target_node->above_median)
			curr_b->cheapest = max(curr_b->push_cost, curr_b->target_node->push_cost);
		else
			curr_b->cheapest = curr_b->push_cost + curr_b->target_node->push_cost;
		curr_b = curr_b->next;
		index++;
	}
}


stack	*find_cheapest(stack *a)
{
	stack *cheapest;
	int		cost;
	
	cost = INT_MAX;
	while (a)
	{
		if (a->cheapest < cost)
		{
			cheapest = a;
			cost = a->cheapest;
		}
		a = a->next;
	}
	return (cheapest);
}