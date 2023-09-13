#include "push_swap.h"

long	ft_atol(char *str)
{
	int	sign;
	long	results;

	sign = 1;
	results = 0;
	while (*str == ' ' || *str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else
		str++;
	while (*str >= '0' && *str <= '9')
	{
		results = results * 10 + *str - '0';
		str++;
	}
	return (results * sign);
}
