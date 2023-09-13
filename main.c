#include "push_swap.h"

int	main(int ac, char **av)
{
	stack	*a;
	stack	*b;


	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = ft_split(av[1]);
	// the last parameter used to see if we need to free the 'av' or not
	stack_init(&a, av + 1, ac == 2);
		
	return (0);
}
