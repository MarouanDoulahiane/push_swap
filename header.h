/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 00:27:21 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/12/03 16:15:31 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include <unistd.h>

//	struct of the stack

typedef struct s_stack
{
	int				val;
	int				index;
	bool			flag;
	int				lenght;
	int				sub_index;
	int				target;
	int				t_val;
	char			nb_mv;
	int				moves;
	int				type;
	struct s_stack	*next;
}	t_stack;

// Get Next Line

char	*get_next_line(int fd);
char	*ft_strdup(const char *s1, char *old_remainder);
char	*ft_strchr(const char *s, int c);
char	*ft_strncpy(char *dest, char *src, unsigned int n);

// Error Handling
void	check_len(char *str, char **matrix, t_stack *a);
void	_free_with_error(char *arr, char *error);
void	free_matrix(char **matrix);
void	_free_2d_with_error(char **matrix, char *error);
bool	_are_digits(char *str);
bool	is_duplicated(t_stack *tmp, int val);
void	_free_list(t_stack *a);
void	if_one_arg_empty_exit(int ac, char **av);

//	setup stack

void	setup_stack_a(t_stack **a, int ac, char **av);

//	longest increasing subsequence 

void	setup_longest(t_stack **a);
t_stack	*get_smallest(t_stack **root);
t_stack	*get_biggest(t_stack *root);
int		get_max_lenght(t_stack *a);

//	stack tools

int		stack_size(t_stack **root);
void	_free_list(t_stack *a);

//	str tools

char	*ft_strjoin_new(char const *s1, char const *s2, bool to_free);
char	**ft_split(char const *s, char c);
int		ft_strlen_new(const char *str);
long	ft_atol(char *str);

//	algo

void	push_to_b(t_stack **a, t_stack **b);
void	push_to_a(t_stack **a, t_stack **b);

// 	push_to_a helpers

void	set_target(t_stack	**a, t_stack **b);
void	calculate_moves_helper(t_stack *curr, int size_a, int size_b);

//	actions

void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);

void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif