#include "push_swap.h"

void	stack_init(stack** node, char*** av, bool to_free, int* size)
{
	int	i;
	long	nb;
	if (syntax_checker(*av))
		free_error(av, to_free);
	i = 0;
	while ((*av)[i])
	{
   		// write(1, "hello\n", 6);
		nb = ft_atol((*av)[i]);
		if (nb > INT_MAX || nb < INT_MIN
			|| duplicated(*node, (int)nb))
			free_error(av, to_free);
		insert_value(node, (int)nb);
		i++;
        *size += 1;
	}
	if (to_free)
		free_matrix(av);
}
