/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:21:37 by eturini           #+#    #+#             */
/*   Updated: 2026/01/12 15:33:56 by eturini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	setup_a(t_stack *a_stack, int *arguments)
{
	size_t	size;

	(void)size;
	(void)(*arguments);
	(void)a_stack;
	return TRUE;
}

int setup_b(t_stack *b_stack)
{
	b_stack->value = 0;
	b_stack->next = NULL;
	b_stack->prev = NULL;
	return (TRUE);
}

void	swap_a(t_stack *a_stack)
{
	(void)a_stack;
}
