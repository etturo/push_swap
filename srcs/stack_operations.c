/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:21:37 by eturini           #+#    #+#             */
/*   Updated: 2025/12/26 23:50:13 by eturini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	setup_a_stack(t_stack *a_stack)
{
	char	*buffer;
	size_t	size;

	(void)size;
	(void)a_stack;
	size = read_from_input(&buffer);
	return TRUE;
}

int setup_b_stack(t_stack *b_stack)
{
	b_stack->value = 0;
	b_stack->next = NULL;
	b_stack->prev = NULL;
	return (TRUE);
}

void	swap_a(t_stack a_stack)
{
	(void)a_stack;
}
