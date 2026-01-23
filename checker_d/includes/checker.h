/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:13:10 by eturini           #+#    #+#             */
/*   Updated: 2026/01/23 16:35:30 by eturini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# include "../../ft_printf/ft_printf.h"

# define TRUE 1
# define FALSE 0
# define ERROR_FLAG 4242424242

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/* checker functions */
int		execute_check(char *op, t_stack **a_stack, t_stack **b_stack);
int		is_sorted(t_stack *stack);
int		checker(t_stack **a_stack, t_stack **b_stack);

/* input handler functions*/
int		check_arg(char **argv);
int		count_arguments(char **argv);
int		fill_the_arguments(char **argv, long **arguments);
int		check_dup(long *arguments, int size);
int		check_input_validity(int argc, char **argv, long **arguments);

/* stack operation functions */
int		setup_a(t_stack **a_stack, long *arguments, int size);
int		fill_a_stack(t_stack **current, long *arguments, int size);
int		swap(t_stack **head);
int		push_b(t_stack **a_stack, t_stack **b_stack);
int		push_a(t_stack **a_stack, t_stack **b_stack);
int		rotate(t_stack **head);
int		rotate_both(t_stack **a_stack, t_stack **b_stack);
int		reverse_rotate(t_stack **head);
int		reverse_rotate_both(t_stack **a_stack, t_stack **b_stack);
int		swap_both(t_stack **a_stack, t_stack **b_stack);

/* error functions */
int		put_error(void);

/* utils functions*/
int		is_number(char c);
int		skip_number(char *s);
int		stack_size(t_stack *stack);
void	free_stack(t_stack *stack);
long	ft_atoi(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif