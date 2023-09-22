#include "push_swap.h"

void	insert_value(stack** node, int value)
{
	stack* new_node;
	stack* curr;
	new_node = (stack*)malloc(sizeof(stack));
	new_node->value = value;

	curr = *node;
	new_node->next = curr;
	*node = new_node;
}

void	swap(stack** node)
{
	stack* first;
	stack* second;
	if (*node == NULL || (*node)->next == NULL)
		return;
	first = *node;
	second = (*node)->next;

	stack* tmp_rest = second->next;
	second->next = first;

	first->next = tmp_rest;

	*node = second;
}

void	push(stack** first, stack** second)
{
	stack* tmp;
	if (*second == NULL)
		return;
	tmp = *second;
	*second = (*second)->next;
	tmp->next = *first;
	*first = tmp;
}

void	rotate(stack** node)
{
	stack* tmp;
	stack* curr;

	if (*node == NULL || (*node)->next == NULL)
		return;
	tmp = *node;
	*node = (*node)->next;
	tmp->next = NULL;
	curr = *node;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = tmp;
}

void	r_rotate(stack** node)
{
	stack* curr;
	if (*node == NULL || (*node)->next == NULL)
		return ;

	curr = *node;
	while (curr->next->next != NULL)
		curr = curr->next;
	stack* tmp = curr->next;
	curr->next = NULL;
	tmp->next = *node;
	*node = tmp;
}

void	sa(stack** a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(stack** b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void 	ss(stack** a, stack** b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

void	pa(stack** a, stack** b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(stack** b, stack** a)
{
	push(b, a);
	write(1, "pb\n", 3);
}

void	ra(stack** a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(stack** b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(stack** a, stack** b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

void	rra(stack** a)
{
	r_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(stack** b)
{
	r_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(stack** a, stack** b)
{
	r_rotate(a);
	r_rotate(b);
	write(1, "rrr\n", 4);
}



