#include "push_swap.h"

int	is_sorted(stack **root)
{
	stack *curr = *root;
	while (curr != NULL)
	{
		if (curr->value > curr->next->value)
			return (1);
		curr = curr->next;
	}
	return (0);
}

int	main(int ac, char** av)
{
	stack*  a;
	stack*  b;
    char**  argv;
    int     size;


	a = NULL;
	b = NULL;
 	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (12);
	else if (ac == 2)
		argv = ft_split(av[1], ' ');
	else if (ac > 2)
		argv = (av + 1);
	stack_init(&a, &argv, ac == 2);


	while (is_sorted(&a))
	{
		if (a->value > a->next->value)
		{
			sa(&a);
		}
	}
	return (0);
}
