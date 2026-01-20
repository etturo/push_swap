/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:19:07 by eturini           #+#    #+#             */
/*   Updated: 2026/01/20 18:03:13 by eturini          ###   ########.fr       */
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

# define ERROR_FLAG 4242424242
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

typedef struct	s_move
{
	int	ra;
	int	rb;
}	t_moves;

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
int		find_cheaper(t_stack *a_stack, t_stack *b_stack, t_moves *moves);
int		find_target(t_stack *a_stack, t_stack *b_stack, int a_pos);
int		execute_move(t_stack **a_stack, t_stack **b_stack);
int		calculate_moves(t_stack *a_stack, t_stack *b_stack, int a_pos, t_moves *move);
int		find_min_moves(int *move, int *comb, t_moves *moves);
void	set_moves(int *move, t_moves *moves, int i);
int		sort_three(t_stack **a_stack);
int		sort_back(t_stack **a_stack, t_stack **b_stack);
int		find_max(t_stack *head);
int		find_min_pos(t_stack *stack);

/* utils functions */;
long	ft_atoi(const char *s);
void	free_stack(t_stack *stack);
int		is_sorted(t_stack *stack);
int		stack_size(t_stack *stack);
int		ft_max(int a, int b);
int		ft_abs(int a);

/* error handling functions */
int		put_error(void);

#endif