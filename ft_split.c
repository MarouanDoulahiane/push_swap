#include "push_swap.h"

char	**ft_split(char *str)
{
	int	i;
	int	j;
	int	k;
	char	**split;
	int	to_free;

	i = 0;
	// we starting from 1 to skip the first argv element
	k = 1;


	if (!(split = (char **)malloc(sizeof(char *) * 256)))
				return (NULL);
	
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i])
	{
		j = 0;
		if (!(split[k] = (char *)malloc(sizeof(char) * 4096)))
		{	
			to_free = 0;
			while (to_free < k)
				free(split[to_free]);
			free(split);
			return (NULL);
		}
		while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			split[k][j++] = str[i++];
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		split[k][j] = 0;
		k++;
	}
	// to create fake argv
	split[k] = NULL;
	return (split);
}
