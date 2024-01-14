/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:47:11 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/11/27 20:01:28 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

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
	push(a, b);
}

void	pb(t_stack **b, t_stack **a)
{
	push(b, a);
}
