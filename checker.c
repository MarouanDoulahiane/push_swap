/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:35:45 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/12/03 17:25:21 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (!s2[i])
			return (s1[i]);
		if (s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
	}
	return (0);
}

bool	is_sorted(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	while (*a && tmp->next)
	{
		if (tmp->val > tmp->next->val)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

void	bad_operation(char *line, t_stack **a, t_stack **b)
{
	write(2, "Error\n", 6);
	_free_list(*a);
	_free_list(*b);
	free(line);
	exit(1);
}

void	handle_operations(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(line, "sa\n"))
		sa(a);
	else if (!ft_strcmp(line, "sb\n"))
		sb(b);
	else if (!ft_strcmp(line, "ss\n"))
		ss(a, b);
	else if (!ft_strcmp(line, "pa\n"))
		pa(a, b);
	else if (!ft_strcmp(line, "pb\n"))
		pb(b, a);
	else if (!ft_strcmp(line, "ra\n"))
		ra(a);
	else if (!ft_strcmp(line, "rb\n"))
		rb(b);
	else if (!ft_strcmp(line, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp(line, "rra\n"))
		rra(a);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(b);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(a, b);
	else
		bad_operation(line, a, b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	setup_stack_a(&a, ac, av);
	line = get_next_line(0);
	while (line)
	{
		handle_operations(line, &a, &b);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(&a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (_free_list(a), _free_list(b), 0);
}
