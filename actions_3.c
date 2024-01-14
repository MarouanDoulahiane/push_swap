/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:47:11 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/11/23 10:32:26 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
	if (rotate(a))
		write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	if (rotate(b))
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	if (rotate(a) && rotate(b))
		write(1, "rr\n", 3);
}
