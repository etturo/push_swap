/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:49:52 by eturini           #+#    #+#             */
/*   Updated: 2026/01/21 16:23:03 by eturini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	rotate(t_stack **head)
{
	t_stack	*last;
	t_stack	*temp;

	if (!*head || !(*head)->prev)
		return (1);
	temp = (*head)->prev;
	last = *head;
	while (last->prev)
		last = last->prev;
	((*head)->prev)->next = NULL;
	(*head)->prev = NULL;
	(*head)->next = last;
	last->prev = *head;
	*head = temp;
	return (1);
}

int	rotate_both(t_stack **a_stack, t_stack **b_stack)
{
	rotate(a_stack);
	rotate(b_stack);
	return (1);
}

int	reverse_rotate(t_stack **head)
{
	t_stack	*last;

	if (!*head || !(*head)->prev)
		return (1);
	last = *head;
	while (last->prev)
		last = last->prev;
	(last->next)->prev = NULL;
	last->next = NULL;
	last->prev = *head;
	(*head)->next = last;
	*head = last;
	return (1);
}

int	reverse_rotate_both(t_stack **a_stack, t_stack **b_stack)
{
	reverse_rotate(a_stack);
	reverse_rotate(b_stack);
	return (1);
}

int	swap_both(t_stack **a_stack, t_stack **b_stack)
{
	swap(a_stack);
	swap(b_stack);
	return (1);
}
