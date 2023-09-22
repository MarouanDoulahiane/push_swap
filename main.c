#include "push_swap.h"

int	not_sorted(stack **root)
{
	stack *curr = *root;
	while (curr->next != NULL)
	{
		if (curr->value > curr->next->value)
		{
			return (1);

		}
		curr = curr->next;
	}
	return (0);
}

int is_bigger(stack** root)
{
    stack*  curr;
    curr = *root;

    while (curr != NULL)
    {
        if ((*root)->value < curr->value)
            return (0);
        curr = curr->next;
    }
    return (1);
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
	stack_init(&a, &argv, ac == 2, &size);


	while (size == 3 && not_sorted(&a))
	{

		if (is_bigger(&a))
		{
			ra(&a);
		}
		if (a->value > a->next->value)
		{
			sa(&a);
		}
		if (a->next->value > a->next->next->value)
		{
			rra(&a);
		}
		if (a->value > a->next->next->value)
		{
			ra(&a);
		}

	}

	for (stack *curr = a; curr != NULL; curr = curr->next)
		printf("value -> %d\n", curr->value);
	return (0);
}
