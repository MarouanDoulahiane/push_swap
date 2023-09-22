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
	int		curr_position;
	int		final_index;
	int		push_price;
	bool		above_median;
	bool		cheapest;
	struct stack	*target_node;
	struct stack	*next;
	struct stack	*prev;
}			stack;

char	**ft_split(char *str, char delimiter);
long	ft_atol(char *str);
void    insert_value(stack **node, int value);
void    stack_init(stack **node, char ***av, bool to_free);
void    sa(stack **node);

// handle errors
bool    duplicated(stack *node, int value);
bool    syntax_checker(char **av);
void    free_error(char ***av, bool to_free);
void    free_matrix(char ***av);





#endif
