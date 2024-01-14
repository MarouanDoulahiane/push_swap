/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:47:11 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/11/27 20:01:59 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool	push(t_stack **first, t_stack **seconde)
{
	t_stack	*tmp;

	if (!seconde || !*seconde)
		return (false);
	tmp = *seconde;
	*seconde = (*seconde)->next;
	tmp->next = *first;
	*first = tmp;
	return (true);
}

void	pa(t_stack **a, t_stack **b)
{
	if (push(a, b))
		write(1, "pa\n", 3);
}

void	pb(t_stack **b, t_stack **a)
{
	if (push(b, a))
		write(1, "pb\n", 3);
}
