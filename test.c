#include "push_swap.h"

long	ft_atol(char *str)
{
	int	sign;
	long	results;

	sign = 1;
	results = 0;
	while (*str != '\0' && (*str == ' ' || *str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		results = results * 10 + *str - '0';
		str++;
	}
	return (results * sign);
}

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



void	swap(stack** node)
{
	stack* first;
	stack* second;
	if (*node == NULL || (*node)->next == NULL)
		return;
	first = *node;
	second = (*node)->next;

	second->prev = NULL;
	stack* tmp_rest = second->next;
	second->next = first;

	first->prev = second;
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
	(*second)->prev = NULL;
	(*first)->prev = tmp;
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
	(*node)->prev = NULL;
	tmp->next = NULL;
	curr = *node;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = tmp;
	tmp->prev = curr;
}

void	r_rotate(stack** node)
{
	stack* tmp;
	stack* curr;
	if (*node == NULL && (*node)->next == NULL)
		return;
	curr = *node;
	while (curr->next != NULL)
		curr = curr->next;
	tmp = curr;
	curr = curr->prev;
	curr->next = NULL;
	tmp->prev = NULL;
	tmp->next = *node;
	(*node)->prev = tmp;
	*node = tmp;
}

void	sa(stack* a)
{
	swap(&a);
	write(1, "sa\n", 3);
}

void	sb(stack* b)
{
	swap(&b);
	write(1, "sb\n", 3);
}

void 	ss(stack* a, stack* b)
{
	swap(&a);
	swap(&b);
	write(1, "ss\n", 3);
}

void	pa(stack* a, stack* b)
{
	push(&a, &b);
	write(1, "pa\n", 3);
}

void	pb(stack* b, stack* a)
{
	push(&b, &a);
	write(1, "pb\n", 3);
}

void	ra(stack* a)
{
	rotate(&a);
	write(1, "ra\n", 3);
}

void	rb(stack* b)
{
	rotate(&b);
	write(1, "rb\n", 3);
}

void	rr(stack* a, stack* b)
{
	rotate(&a);
	rotate(&b);
	write(1, "rr\n", 3);
}

void	rra(stack* a)
{
	r_rotate(&a);
	write(1, "rra\n", 4);
}

void	rrb(stack* b)
{
	r_rotate(&b);
	write(1, "rrb\n", 4);
}

void	rrr(stack* a, stack* b)
{
	r_rotate(&a);
	r_rotate(&b);
	write(1, "rrr\n", 4);
}



void	insert_value(stack** node, int value)
{
	stack* new_node;
	stack* curr;
	new_node = (stack*)malloc(sizeof(stack));
	new_node->value = value;
	new_node->next = NULL;
	if (*node == NULL)
	{
		new_node->prev = NULL;
		*node = new_node;
		return;
	}
	curr = *node;
	while (curr->next != NULL)
		curr = curr->next;
	new_node->prev = curr;
	curr->next = new_node;
}

int count_word(char *str, char delimiter)
{
  int count = 0;
  while (*str != '\0')
  {
    while (*str != '\0' && *str == delimiter)
      str++;
    while (*str != '\0' && *str != delimiter)
    {
      str++;
      if (*str == '\0' || *str == delimiter)
        count++;

    }
  }
  return (count);
}

int len_word(char *str, char delimiter)
{
  int len = 0;
  while  (*str != '\0' && *str != delimiter)
  {
    len++;
    str++;
  }
  return (len);
}

char** ft_split(char* str, char delimiter)
{
  char **arr;
  int len = 0;
  int k = 0;
  int i;
  arr = (char **)malloc(sizeof(char*) * (count_word(str, delimiter) + 1));
  if (!arr)
    return (NULL);
  while(*str != '\0')
  {
    while (*str != '\0' && *str == delimiter)
      str++;
    if (*str != '\0')
    {
      i = 0;
      len = len_word(str, delimiter);
      arr[k] = (char *)malloc(sizeof(char) * (len + 1));
      if (!arr[k])
        return (NULL);
      while (*str != '\0' && *str != delimiter)
      {
        arr[k][i] = *str;
        i++;
        str++;
      }
      arr[k][i] = '\0';
      k++;
    }
  }
  arr[k] = NULL;
  return (arr);
}

void	stack_init(stack** node, char*** av, bool to_free)
{
	int	i;
	long	nb;
	if (syntax_checker(*av))
		free_error(av, to_free);
	i = 0;
	while ((*av)[i])
	{
		nb = ft_atol((*av)[i]);
		if (nb > INT_MAX || nb < INT_MIN
			|| duplicated(*node, (int)nb))
			free_error(av, to_free);
		insert_value(node, (int)nb);
		i++;
	}
}

int ac = 4;
char *av[] = {(char *)"jooj\0", (char *)"1", (char *)"4", (char *)"124"};

int	main()
{
	stack* a;
	stack* b;


	a = NULL;
	b = NULL;
  char **argv;
  
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (12);
	else if (ac == 2)
		argv = ft_split(av[1], ' ');
  	else if (ac > 2)
		argv = (av + 1);
	// the last parameter used to see if we need to free the 'av' or not
	stack_init(&a, &argv, ac == 2);

	return (0);
}
