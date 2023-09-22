#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

typedef struct	stack
{
	int		value;
	struct stack	*next;
}			stack;

char	**ft_split(char *str, char delimiter);
long	ft_atol(char *str);
void    insert_value(stack **node, int value);
void    stack_init(stack **node, char ***av, bool to_free, int* size);

// moves
void    sa(stack **a);
void	sb(stack** b);
void 	ss(stack** a, stack** b);
void	pa(stack** a, stack** b);
void	pb(stack** a, stack** b);
void	ra(stack** a);
void	rb(stack** b);
void	rr(stack** a, stack** b);
void	rra(stack** a);
void	rrb(stack** b);
void	rrr(stack** a, stack** b);


// handle errors
bool    duplicated(stack *node, int value);
bool    syntax_checker(char **av);
void    free_error(char ***av, bool to_free);
void    free_matrix(char ***av);


// Sort Algorithm
void   tiny_sort(stack** a);





#endif
