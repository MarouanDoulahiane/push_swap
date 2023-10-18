/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 02:33:04 by marvin            #+#    #+#             */
/*   Updated: 2023/10/15 02:33:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(stack **root)
{
	stack	*first;
	stack	*second;

	if (*root == NULL || (*root)->next == NULL)
		return ;
	first = *root;
	second = (*root)->next;
	*root = second;
	first->next = second->next;
	second->next = first; 
}

void	sa(stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(stack **a, stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

void	push(stack **first, stack **second)
{
	stack	*f_tmp;
	stack	*s_tmp;

	if (*second == NULL)
		return ;
	s_tmp = *second;
	*second = (*second)->next;
	s_tmp->next = *first;
	*first = s_tmp;
}

void	pa(stack **a, stack **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(stack **b, stack **a)
{
	push(b, a);
	write(1, "pb\n", 3);
}

void	rotate(stack **root)
{
	stack	*fst;
	stack	*curr;

	if (*root == NULL || (*root)->next == NULL)
		return ;
	fst = *root;
	*root = (*root)->next;
	curr = *root;
	while (curr->next)
		curr = curr->next;
	curr->next = fst;
	fst->next = NULL;
}

void	ra(stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(stack **a, stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

void	reverse(stack **root)
{
	stack	*last;
	stack	*prev;

	if (*root == NULL || (*root)->next == NULL)
		return ;
	last = *root;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;	
	last->next = *root;
	*root = last;
}

void	rra(stack **a)
{
	reverse(a);
	write(1, "rra\n", 4);
}

void	rrb(stack **b)
{
	reverse(b);
	write(1, "rrb\n", 4);
}

void	rrr(stack **a, stack **b)
{
	reverse(a);
	reverse(b);
	write(1, "rrr\n", 4);
}