/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_stack_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:01:36 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/11/27 11:47:06 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix && matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	_free_2d_with_error(char **matrix, char *error)
{
	free_matrix(matrix);
	if (error)
		write(2, error, ft_strlen_new(error));
	exit(1);
}

void	_free_with_error(char *arr, char *error)
{
	free(arr);
	if (error)
		write(2, error, ft_strlen_new(error));
	exit(1);
}

bool	_are_digits(char *str)
{
	int	i;

	i = 0;
	if (str[i + 1] && (str[i] == '-' || str[i] == '+'))
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (false);
		i++;
	}
	return (true);
}

bool	is_duplicated(t_stack *tmp, int val)
{
	while (tmp)
	{
		if (tmp->val == val)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}
