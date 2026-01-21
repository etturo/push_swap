/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:19:07 by eturini           #+#    #+#             */
/*   Updated: 2026/01/21 17:10:09 by eturini          ###   ########.fr       */
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

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_move
{
	int	ra;
	int	rb;
}	t_moves;

/* algorithm.c */
int		execute_move(t_stack **a_stack, t_stack **b_stack);
int		calculate_moves(t_stack *a_stack, t_stack *b_stack, int a_pos,
			t_moves *move);
int		find_n_rotation(t_stack *a_stack, int value);
int		sort_back(t_stack **a_stack, t_stack **b_stack);
void	final_rotate(t_stack **a_stack);

/* calculation.c & calculation2.c */
int		find_cheaper(t_stack *a_stack, t_stack *b_stack, t_moves *moves);
int		find_min_moves(int *move, int *comb, t_moves *moves);
int		find_min(t_stack *head);
int		find_max(t_stack *head);
int		find_max_pos(t_stack *head);
int		find_min_pos(t_stack *stack);
int		find_target(t_stack *a_stack, t_stack *b_stack, int a_pos);
void	set_moves(int *move, t_moves *moves, int i);

/* error_handler.c */
int		put_error(void);

/* input_handler.c */
int		check_input_validity(int argc, char **argv, long **arguments);
int		count_arguments(char **argv);
int		fill_the_arguments(char **argv, long **arguments);
int		check_arg(char **argv);
int		check_dup(long *arguments, int size);

/* math_functions.c */
int		ft_abs(int a);
int		ft_max(int a, int b);
int		ft_min(int a, int b);

/* push_swap.c */
void	push_swap(t_stack **a_stack, t_stack **b_stack);

/* sort_functions.c */
int		sort_two(t_stack **a_stack);
int		sort_three(t_stack **a_stack);
int		is_sorted(t_stack *stack);
void	index_sorting(t_stack **stack, long *arguments);
long	*bubble_sort(long *num, int size);

/* stack_operations.c & stack_operations_2.c */
int		setup_a(t_stack **a_stack, long *arguments, int size);
int		fill_a_stack(t_stack **current, long *arguments, int size);
int		swap(t_stack **head, int stack_flag);
int		push_b(t_stack **a_stack, t_stack **b_stack);
int		push_a(t_stack **a_stack, t_stack **b_stack);
int		rotate(t_stack **head, int flag);
int		rotate_both(t_stack **a_stack, t_stack **b_stack);
int		reverse_rotate(t_stack **head, int flag);
int		reverse_rotate_both(t_stack **a_stack, t_stack **b_stack);
int		swap_both(t_stack **a_stack, t_stack **b_stack);

/* utils_functions.c */
long	ft_atoi(const char *s);
void	free_stack(t_stack *stack);
int		stack_size(t_stack *stack);
int		skip_number(char *s);
int		is_number(char c);

#endif