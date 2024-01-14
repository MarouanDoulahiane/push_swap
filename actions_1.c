/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:47:11 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/11/23 10:31:49 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool	swap(t_stack **root)
{
	t_stack	*tmp;

	if (!*root || !(*root)->next)
		return (false);
	tmp = *root;
	*root = (*root)->next;
	tmp->next = (*root)->next;
	(*root)->next = tmp;
	return (true);
}

void	sa(t_stack **a)
{
	if (swap(a))
		write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	if (swap(b))
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	if (swap(a) && swap(b))
		write(1, "ss\n", 3);
}
