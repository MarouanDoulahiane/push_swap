/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 02:25:14 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/11/23 10:32:45 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
	if (reverse(a))
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	if (reverse(b))
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	if (reverse(a) && reverse(b))
		write(1, "rrr\n", 4);
}
