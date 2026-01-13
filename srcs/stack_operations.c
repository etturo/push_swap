/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:21:37 by eturini           #+#    #+#             */
/*   Updated: 2026/01/13 22:04:44 by eturini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	setup_a(t_stack **a_stack, long *arguments)
{
	t_stack	*current;
	t_stack *temp;

	current = (t_stack *)malloc(sizeof(t_stack));
	if (!current)
		return FALSE;
	current->value = (int)*arguments;
	current->prev = NULL;
	current->next = NULL;
	*a_stack = current;
	arguments++;
	while ((*arguments) != END_VALUE)
	{
		temp = (t_stack *)malloc(sizeof(t_stack));
		if (!temp)
			return FALSE;
		temp->prev = current;
		current->prev = temp;
		current = temp;
		current->value = (int)*arguments;
		current->prev = NULL;
		arguments++;
	}
	return (TRUE);
}

void	swap_a(t_stack *a_stack)
{
	if (!a_stack || !a_stack->prev)
		return ;
	
}
