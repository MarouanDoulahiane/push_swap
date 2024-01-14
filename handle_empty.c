/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_empty.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:25:37 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/12/03 16:25:43 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool	if_one_helep(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

void	if_one_arg_empty_exit(int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (if_one_helep(av[i]))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}
