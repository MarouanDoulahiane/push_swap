/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 02:25:14 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/11/23 12:34:38 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

bool	reverse(t_stack **root)
{
	t_stack	*prev;
	t_stack	*last;

	if (!*root || !(*root)->next)
		return (NULL);
	last = *root;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	last->next = *root;
	prev->next = NULL;
	*root = last;
	return (true);
}

void	rra(t_stack **a)
{
	reverse(a);
}

void	rrb(t_stack **b)
{
	reverse(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse(a);
	reverse(b);
}
