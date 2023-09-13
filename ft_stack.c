#include "push_swap.h"

void	stack_init(stack **node, char **av, bool to_free)
{
	int	i;
	long	nb;
	if (syntax_checker(av))
		free_errer(av, to_free);
	i = 0;
	while (av[i])
	{
		nb = ft_atol(av[i]);
		if (nb > MAX_INT || nb < MIN_INT
				|| duplicated(*node, (int)nb))
			free_errer(av, to_free);
		insert_value(node, (int)nb);
		i++;
	}
}
