/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:19:07 by eturini           #+#    #+#             */
/*   Updated: 2026/01/13 21:45:56 by eturini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define TRUE 1
# define FALSE 0

# define END_VALUE 4242424242

typedef struct	s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/* main functions */
void		push_swap(void);

/* file handler functions, and input validation */
int		check_input_validity(int argc, char **argv, long **arguments);
int		count_arguments(char **argv);
int		fill_the_arguments(char **argv, long **arguments);
int		check_arg(char **argv);
int		check_dup(long *arguments);

/* stack operations on the stacks */
int		setup_b(t_stack **b_stack);
int		setup_a(t_stack **a_stack, long *arguments);
void	swap_a(t_stack *a_stack);

/* utils functions */;
long	ft_atoi(const char *s);
void	free_stack(t_stack *stack);

/* error handling functions */
int		put_error(void);

#endif