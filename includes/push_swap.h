/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:19:07 by eturini           #+#    #+#             */
/*   Updated: 2026/01/17 17:40:07 by eturini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# include "../ft_printf/ft_printf.h"

# define TRUE 1
# define FALSE 0

# define NULL_FLAG 0
# define A_FLAG 1
# define B_FLAG 2
# define BOTH_FLAG 3

typedef struct	s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/* main functions */
void	push_swap(t_stack **a_stack, t_stack **b_stack, long *arguments);

/* file handler functions, and input validation */
int		check_input_validity(int argc, char **argv, long **arguments);
int		count_arguments(char **argv);
int		fill_the_arguments(char **argv, long **arguments);
int		check_arg(char **argv);
int		check_dup(long *arguments, int size);

/* stack operations on the stacks */
int		setup_b(t_stack **b_stack);
int		setup_a(t_stack **a_stack, long *arguments, int size);
int		swap(t_stack **head, int stack_flag);
int		swap_both(t_stack **a_stack, t_stack **b_stack);
int		push_a(t_stack **a_stack, t_stack **b_stack);
int		push_b(t_stack **a_stack, t_stack **b_stack);
int		rotate(t_stack **head, int flag);
int		rotate_both(t_stack **a_stack, t_stack **b_stack);
int		reverse_rotate(t_stack **head, int flag);
int		reverse_rotate_both(t_stack **a_stack, t_stack **b_stack);

/* algorithm functions */
void	index_sorting(t_stack **stack, long *arguments);
long	*bubble_sort(long *num, int size);
int		is_sorted(t_stack *stack);

/* utils functions */;
long	ft_atoi(const char *s);
void	free_stack(t_stack *stack);
int		is_sorted(t_stack *stack);
int		stack_size(t_stack *stack);

/* error handling functions */
int		put_error(void);

#endif