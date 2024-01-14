/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_longest_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:42:47 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/11/23 10:19:28 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_stack	*get_biggest(t_stack *root)
{
	t_stack	*tmp;
	t_stack	*biggest;

	tmp = root;
	biggest = tmp;
	while (tmp)
	{
		if (tmp->val > biggest->val)
			biggest = tmp;
		tmp = tmp->next;
	}
	return (biggest);
}

t_stack	*get_smallest(t_stack **root)
{
	t_stack	*smaller;
	t_stack	*curr;
	int		min;

	stack_size(root);
	min = INT_MAX;
	smaller = NULL;
	curr = *root;
	while (curr)
	{
		if (curr->val < min)
		{
			smaller = curr;
			min = curr->val;
		}
		curr = curr->next;
	}
	return (smaller);
}

int	get_max_lenght(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->lenght > i)
			i = a->lenght;
		a = a->next;
	}
	return (i);
}
