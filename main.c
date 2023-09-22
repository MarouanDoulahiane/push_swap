#include "push_swap.h"


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
	stack_init(&a, &argv, ac == 2, &size);

	if (size == 3)
		tiny_sort(&a);

	for (stack *curr = a; curr != NULL; curr = curr->next)
		printf("value -> %d\n", curr->value);
	return (0);
}
