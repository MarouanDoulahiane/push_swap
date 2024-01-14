/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:33:16 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/12/03 17:25:09 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	set_smaller_at_the_top(t_stack **a)
{
	t_stack	*tmp;
	int		size;

	if (!a || !*a)
		return ;
	size = stack_size(a);
	tmp = get_smallest(a);
	while (tmp->index <= size / 2 && tmp->index)
	{
		ra(a);
		tmp->index--;
	}
	while (tmp->index > size / 2 && tmp->index < size)
	{
		rra(a);
		tmp->index++;
	}
}

void	sort_three(t_stack **a)
{
	t_stack	*bigger;

	bigger = get_biggest(*a);
	if (bigger->val == (*a)->val)
		ra(a);
	else if (bigger->val == (*a)->next->val)
		rra(a);
	if ((*a)->val > (*a)->next->val)
		sa(a);
}

bool	is_sorted(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (a && tmp->next)
	{
		if (tmp->val > tmp->next->val)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

void	sort_five(t_stack **a, t_stack **b)
{
	pb(b, a);
	if (stack_size(a) == 4)
		pb(b, a);
	sort_three(a);
	push_to_a(a, b);
	set_smaller_at_the_top(a);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	setup_stack_a(&a, ac, av);
	if (!is_sorted(a))
	{
		if (stack_size(&a) == 2)
			sa(&a);
		else if (stack_size(&a) == 3)
			sort_three(&a);
		else if (stack_size(&a) <= 5)
			sort_five(&a, &b);
		else
		{
			push_to_b(&a, &b);
			push_to_a(&a, &b);
			set_smaller_at_the_top(&a);
		}
	}
	return (_free_list(a), _free_list(b), 0);
}
