/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 02:07:27 by marvin            #+#    #+#             */
/*   Updated: 2023/10/10 02:07:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	counter(char const *s, char c)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			size++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (size);
}

char	*get_word(int *index, char const *s, char c)
{
	char	*res;
	int		size;
	int		i;

	size = 0;
	i = 0;
	while (s[*index] == c && s[*index])
		(*index)++;
	while (s[*index] != c && s[*index])
	{
		(*index)++;
		size++;
	}
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	while (i < size)
	{
		res[i] = s[*index - size + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	**free2d(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (NULL);
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}
#include <string.h>
char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		wc;
	int		i;
	int		index;

	if (!s)
		return (NULL);
	wc = counter(s, c) + 1;
	arr = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!arr)
		return (NULL);
	i = 1;
	index = 0;
	while (i < wc)
	{
		arr[i] = get_word(&index, s, c);
		if (!arr[i])
			return (free2d(arr));
		i++;
	}
	arr[0] = strdup("nothing");
	arr[i] = NULL;
	return (arr);
}

long	ft_atol(char *str)
{
	long 	nb;
	int		signe;
	int		i;

	signe = 1;
	nb = 0;
	i = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	return (nb * signe);
}
