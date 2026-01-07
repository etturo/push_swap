/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:19:07 by eturini           #+#    #+#             */
/*   Updated: 2026/01/07 19:30:11 by eturini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define TRUE 1
# define FALSE 0

typedef struct	s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/* main functions */
void	push_swap(void);

/* file handler functions, and input validation */
int		check_input_validity(int argc, char **argv, int **arguments);

/* stack operations on the stacks */
void	swap_a(t_stack a_stack);
int		setup_a_stack(t_stack *a_stack, int *arguments);
int		setup_b_stack(t_stack *b_stack);

/* utils functions */
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);

#endif