/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:22:19 by marvin            #+#    #+#             */
/*   Updated: 2023/10/14 23:22:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(stack *a)
{
	while(a)
	{
		printf("%d\n", a->val);
		a = a->next;
	}
}

int	main(int argc, char **argv)
{
	stack	*a;
	stack	*b;
	int		len;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	init_stack_a(&a, &argv, argc == 2);

	if (!stack_sorted(a))
	{
		len = stack_len(a);
		if (len == 2)
			sa(&a);
		else if (len == 3)
			sort_three(&a);
		else if (len > 3)
			sort_algo(&a, &b);
	}
	// // print_stack(a);

	// if (stack_sorted(a))
	// 	printf("You are a God!!!\n");

	if (argc == 2)
		free_argv(&argv);
	free_stack(&a);
	return (0);
}