/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:21:37 by eturini           #+#    #+#             */
/*   Updated: 2026/01/13 18:36:04 by eturini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	setup_a(t_stack **a_stack, long long *arguments)
{
	t_stack	*current;
	t_stack *temp;

	current = (t_stack *)malloc(sizeof(t_stack));
	if (!current)
		return FALSE;
	current->value = (int)*arguments;
	current->prev = NULL;
	current->next = NULL;
	arguments++;
	while ((*arguments) != END_VALUE)
	{
		temp = (t_stack *)malloc(sizeof(t_stack));
		if (!temp)
			return FALSE;
		temp->prev = current;
		current->next = temp;
		current = temp;
		current->value = (int)*arguments;
		current->next = NULL;
		arguments++;
	}
	*a_stack = current;
	return (TRUE);
}

int setup_b(t_stack **b_stack)
{
	*b_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!b_stack)
		return (FALSE);
	(*b_stack)->value = 0;
	(*b_stack)->next = NULL;
	(*b_stack)->prev = NULL;
	return (TRUE);
}

void	swap_a(t_stack *a_stack)
{
	(void)a_stack;
}
