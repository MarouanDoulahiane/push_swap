/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:14:11 by marvin            #+#    #+#             */
/*   Updated: 2023/10/15 13:14:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack	*find_last(stack *a)
{
	while (a->next)
		a = a->next;
	return (a);
}

void	append_node(stack **a, int val)
{
	stack	*node;
	stack	*last;

	node = malloc(sizeof(stack));
	if (!node)
		return ;
	node->next = NULL;
	node->val = val;
	if (!*a)
	{
		*a = node;
	}
	else
	{
		last = find_last(*a);
		last->next = node;
	}
}

bool	stack_sorted(stack *a)
{
	while (a->next)
	{
		if (a->val > a->next->val)
			return (false);
		a = a->next;
	}
	return (true);
}

size_t	stack_len(stack *a)
{
	size_t	i;

	i = 0;
	if (a == NULL)
		exit(1);
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}
