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

int is_bigger(stack** root, int value)
{
    stack*  curr;
    curr = *root;

    while (curr != NULL)
    {
        if (value < curr->value)
            return (0);
        curr = curr->next;
    }
    return (1);
}


/*
    IF THE 1* IS THE BIGGEST, ra
    IF THE 2* IS THE BIGGEST, rra
    AT THE END WE CHECK 1* AND 2* iF (1* > 2*)? sa : nullptr;
*/

void   tiny_sort(stack** a)
{
    if (is_bigger(a, (*a)->value))
        ra(a);
    else  if (is_bigger(a, (*a)->next->value))
        rra(a);
    if ((*a)->value > (*a)->next->value)
        sa(a);
}