/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:47:11 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/11/23 12:34:53 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

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
	swap(a);
}

void	sb(t_stack **b)
{
	swap(b);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
}
