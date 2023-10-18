/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:36:58 by marvin            #+#    #+#             */
/*   Updated: 2023/10/14 23:36:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool error_syntax(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if(!(str[i] >= '0' && str[i] <= '9'))
			return (true);
		i++;
	}
	return (false);
}

bool error_duplicate(stack *a, int n)
{
	while (a)
	{
		if (a->val == n)
			return (true);
		a = a->next;
	}
	return (false);
}


void	free_stack(stack **a)
{
	stack	*tmp;

	while (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		free(tmp);
	}
}

void	free_argv(char ***argv)
{
	int	i;

	i = 0;
	while ((*argv)[i])
	{
		free((*argv)[i]);
		i++;
	}
	free(*argv);
}

void	free_error(stack **a, char ***argv, bool for_free)
{
	int		i;

	i = 0;
	if (for_free)
	{
		free_argv(argv);
	}
	free_stack(a);
	exit(1);
}

int	max(int a, int b)
{
	return ((a < b)? b : a);
}