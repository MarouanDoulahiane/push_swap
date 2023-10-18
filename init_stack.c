/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:12:21 by marvin            #+#    #+#             */
/*   Updated: 2023/10/15 13:12:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_a(stack **a, char ***argv, bool for_free)
{
	long	n;
	int		i;

	i = 1;
	while ((*argv)[i])
	{
		if (error_syntax((*argv)[i]))
			free_error(a, argv, for_free);
		n = ft_atol((*argv)[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_error(a, argv, for_free);
		if (error_duplicate(*a, (int)n))
			free_error(a, argv, for_free);
		append_node(a, (int)n);
		i++;
	}
}
