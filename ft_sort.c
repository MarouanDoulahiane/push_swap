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

stack*	find_smallest(stack *a)
{
	stack*	smallest;
	stack*	curr;
	int		value;
	curr = a;
	value = INT_MAX;
	while (curr != NULL)
	{
		if (value > curr->value)
			smallest = curr;
		curr = curr->next;
	}
	return smallest;
}

void	set_target_node(stack *a, stack *b)
{
	stack*	curr_a;
	stack*	target_node;
	int		target_value;

	while (b)
	{
		target_value = INT_MAX;
		curr_a = a;
		while (curr_a)
		{
			// we trying here to find the smallest-bigger node
			if (curr_a->value > b->value && target_value < curr_a->value )
			{
				target_node = curr_a;
				target_value = curr_a->value;
			}
			curr_a = curr_a->next;
		}
		// here we check if we don't find the smallest-bigger, than we try to find the smallest node to make it easy for as (ra)
		if (target_value == INT_MAX)
			b->target_node = find_smallest(a);
		else
			b->target_node = target_value;
		b = b->next;
	}
}