#include "push_swap.h"

void	free_matrix(char*** av)
{
	if (av == NULL || *av == NULL)
		exit(400);
	int size = 0;
	while ((*av)[size] != NULL) {
		size++;
	}
	while (size--)
	{
		free((*av)[size]);
		(*av)[size] = NULL;
	}
	free(*av);
	//exit(-42);
}


void	free_error(char*** av, bool to_free)
{
	write(2, "Error\n", 6);
	if (to_free)
		free_matrix(av);
	exit(200);
}


bool    syntax_checker(char** av)
{
    int    i;
    int    nb;
    int    sign;
    int index = 0;

    while (av[index])
    {
        i = 0;
        sign = 0;
        nb = 0;
        while (av[index][i] != '\0')
        {
            if (!((av[index][i]  == '-' || av[index][i]  == '+') || (av[index][i]  >= '0'
                && av[index][i]  <= '9')))
                return (true);
            else if (av[index][i]  >= '0' && av[index][i]  <= '9')
                nb++;
            else
                sign++;
            i++;
        }
        if (sign > 1 || nb == 0)
            return (true);
        index++;
    }
    return (false);
}

bool	duplicated(stack* node, int value)
{
	stack* curr;

	if (node == NULL)
		return (false);
	curr = node;
	while (curr != NULL)
	{
		if (curr->value == value)
			return (true);
		curr = curr->next;
	}
	return (false);
}


