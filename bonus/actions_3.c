/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:47:11 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/11/23 12:34:47 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

bool	rotate(t_stack **root)
{
	t_stack	*tmp;
	t_stack	*curr;

	if (!*root || !(*root)->next)
		return (false);
	tmp = *root;
	*root = (*root)->next;
	curr = *root;
	while (curr->next)
	{
		curr = curr->next;
	}
	curr->next = tmp;
	tmp->next = NULL;
	return (true);
}

void	ra(t_stack **a)
{
	rotate(a);
}

void	rb(t_stack **b)
{
	rotate(b);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}
