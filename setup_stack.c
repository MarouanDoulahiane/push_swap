/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:02:53 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/12/03 16:33:30 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	_free_list_with_exit(t_stack *a, char **matrix)
{
	t_stack	*tmp;

	while (matrix && *matrix)
	{
		free(*matrix);
		matrix++;
	}
	free(matrix);
	tmp = a;
	while (tmp)
	{
		a = a->next;
		free(tmp);
		tmp = a;
	}
	exit(1);
}

void	push_to_stack(t_stack **root, int val, char **matrix)
{
	t_stack	*new;
	t_stack	*tmp;

	if (!root)
		_free_2d_with_error(matrix, NULL);
	new = malloc(sizeof(t_stack));
	if (!new)
		_free_list_with_exit(*root, matrix);
	new->val = val;
	new->flag = false;
	new->sub_index = -1;
	new->lenght = 1;
	new->type = -1;
	new->next = NULL;
	if (!*root)
		*root = new;
	else
	{
		tmp = *root;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	_free_matrix_with_stack(char **matrix, t_stack *a)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	while (matrix && matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	tmp = a;
	while (tmp)
	{
		a = a->next;
		free(tmp);
		tmp = a;
	}
	write(2, "Error\n", 6);
	exit(1);
}

void	check_args_and_fill_stack(t_stack **a, char **matrix)
{
	int		i;
	long	tmp;

	i = 0;
	while (matrix[i])
	{
		if (!_are_digits(matrix[i]))
			_free_matrix_with_stack(matrix, *a);
		check_len(matrix[i], matrix, *a);
		tmp = ft_atol(matrix[i]);
		if (tmp > INT_MAX || tmp < INT_MIN || is_duplicated(*a, tmp))
			_free_matrix_with_stack(matrix, *a);
		push_to_stack(a, (int)tmp, matrix);
		i++;
	}
}

void	setup_stack_a(t_stack **a, int ac, char **av)
{
	char	*args;
	char	**matrix;
	int		i;

	if_one_arg_empty_exit(ac - 1, av + 1);
	i = 2;
	args = ft_strjoin_new(av[1], " ", false);
	if (!args)
		exit(1);
	while (i < ac)
	{
		args = ft_strjoin_new(args, av[i], true);
		if (!args)
			_free_with_error(args, NULL);
		args = ft_strjoin_new(args, " ", true);
		if (!args)
			_free_with_error(args, NULL);
		i++;
	}
	matrix = ft_split(args, ' ');
	if (!matrix)
		_free_with_error(args, NULL);
	check_args_and_fill_stack(a, matrix);
	free_matrix(matrix);
}
