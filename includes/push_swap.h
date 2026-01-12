/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:19:07 by eturini           #+#    #+#             */
/*   Updated: 2026/01/12 18:02:13 by eturini          ###   ########.fr       */
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
int		count_arguments(char **argv);
int		fill_the_arguments(char **argv, int **arguments);

/* stack operations on the stacks */
void	swap_a(t_stack *a_stack);
int		setup_a_stack(t_stack *a_stack, int *arguments);
int		setup_b_stack(t_stack *b_stack);

/* utils functions */
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *s);

/* error handling functions */
int		put_error(void);

#endif