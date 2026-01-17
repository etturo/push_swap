/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:21:37 by eturini           #+#    #+#             */
/*   Updated: 2026/01/17 16:26:16 by eturini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int setup_a(t_stack **a_stack, long *arguments, int size)
{
	t_stack *current;
	t_stack *new_node;
	t_stack	*head;
	int		i;

	i = 0;
	current = *a_stack;
	current = (t_stack *)malloc(sizeof(t_stack));
	if (!current)
		return (FALSE);
	current->value = (int)*arguments;
	current->prev = NULL;
	current->next = NULL;
	head = current;
	arguments++;
	while (++i < size)
	{
		new_node = (t_stack *)malloc(sizeof(t_stack));
		if (!new_node)
			return (FALSE);
		new_node->value = (int)*arguments;
		new_node->prev = NULL;
		new_node->next = current;
		current->prev = new_node;
		current = new_node;
		arguments++;
	}
	*a_stack = head;
	return (TRUE);
}

int	swap(t_stack **head, int stack_flag)
{
	t_stack *temp;

	if (!*head || !(*head)->prev)
		return 1;
	temp = *head;
	*head = (*head)->prev;
	temp->next = *head;
	if ((*head)->prev)
	{
		((*head)->prev)->next = temp;
		temp->prev = (*head)->prev;
	}
	else
		temp->prev = NULL;
	(*head)->prev = temp;
	temp->next = *head;
	(*head)->next = NULL;
	if (stack_flag == A_FLAG)
		ft_printf("sa\n");
	if (stack_flag == B_FLAG)
		ft_printf("sb\n");
	return 1;
}

int	swap_both(t_stack **a_stack, t_stack **b_stack)
{
	swap(a_stack, NULL_FLAG);
	swap(b_stack, NULL_FLAG);
	ft_printf("ss\n");
	return 1;
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
	ft_printf("pb\n");
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
	ft_printf("pa\n");
	return (1);
}
