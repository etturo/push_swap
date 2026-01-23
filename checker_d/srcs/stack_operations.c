/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:21:37 by eturini           #+#    #+#             */
/*   Updated: 2026/01/23 11:27:10 by eturini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	setup_a(t_stack **a_stack, long *arguments, int size)
{
	t_stack	*current;
	t_stack	*head;

	current = *a_stack;
	current = (t_stack *)malloc(sizeof(t_stack));
	if (!current)
		return (FALSE);
	current->value = (int)arguments[0];
	current->prev = NULL;
	current->next = NULL;
	head = current;
	arguments++;
	*a_stack = current;
	if (fill_a_stack(a_stack, arguments, size) == FALSE)
		return (FALSE);
	*a_stack = head;
	return (TRUE);
}

int	fill_a_stack(t_stack **current, long *arguments, int size)
{
	t_stack	*new_node;
	int		i;

	i = 1;
	while (i < size)
	{
		new_node = (t_stack *)malloc(sizeof(t_stack));
		if (!new_node)
			return (FALSE);
		new_node->value = (int)*arguments;
		new_node->prev = NULL;
		new_node->next = *current;
		(*current)->prev = new_node;
		(*current) = new_node;
		arguments++;
		i++;
	}
	return (TRUE);
}

int	swap(t_stack **head)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!head || !*head || !(*head)->prev)
		return (0);
	first = *head;
	second = first->prev;
	third = second->prev;
	*head = second;
	second->next = NULL;
	second->prev = first;
	first->next = second;
	first->prev = third;
	if (third)
		third->next = first;
	return (1);
}

int	push_b(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*temp;

	if (!*a_stack)
		return (1);
	temp = *a_stack;
	*a_stack = (*a_stack)->prev;
	if (*a_stack)
		(*a_stack)->next = NULL;
	temp->prev = *b_stack;
	temp->next = NULL;
	if (*b_stack)
		(*b_stack)->next = temp;
	*b_stack = temp;
	return (1);
}

int	push_a(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*temp;

	if (!*b_stack)
		return (1);
	temp = *b_stack;
	*b_stack = (*b_stack)->prev;
	if (*b_stack)
		(*b_stack)->next = NULL;
	temp->prev = *a_stack;
	temp->next = NULL;
	if (*a_stack)
		(*a_stack)->next = temp;
	*a_stack = temp;
	return (1);
}
