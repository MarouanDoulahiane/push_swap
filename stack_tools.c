/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:17:44 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/11/27 12:05:21 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	stack_size(t_stack **root)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *root;
	while (tmp)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	_free_list(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp)
	{
		a = a->next;
		free(tmp);
		tmp = a;
	}
}

void	check_len(char *str, char **matrix, t_stack *a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
		i++;
	while (str[i + j] && str[i + j] == '0')
		j++;
	while (str[i + j])
		i++;
	if (i > 12)
	{
		free_matrix(matrix);
		_free_list(a);
		write(2, "Error\n", 6);
		exit(1);
	}
}
