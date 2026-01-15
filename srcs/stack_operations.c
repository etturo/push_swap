/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:21:37 by eturini           #+#    #+#             */
/*   Updated: 2026/01/15 16:11:42 by eturini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	setup_a(t_stack **a_stack, long *arguments)
{
	t_stack	*current;
	t_stack *temp;

	current = (t_stack *)malloc(sizeof(t_stack));
	if (!current)
		return (FALSE);
	current->value = (int)*arguments;
	current->prev = NULL;
	current->next = NULL;
	*a_stack = current;
	arguments++;
	while ((*arguments) != END_VALUE)
	{
		temp = (t_stack *)malloc(sizeof(t_stack));
		if (!temp)
			return (FALSE);
		temp->prev = current;
		temp->next = NULL;
		current->prev = temp;
		current = temp;
		current->value = (int)*arguments;
		current->prev = NULL;
		arguments++;
	}
	return (TRUE);
}

int	swap(t_stack **head, int stack_flag)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = *head;
	if (!first || !first->prev)
		return 1;
	second = first->prev;
	third = second->prev;
	third->next = first;
	second->next = NULL;
	first->next = second;
	first->prev = third;
	second->prev = first;
	if (stack_flag == A_FLAG)
		ft_printf("sa\n");
	if (stack_flag == B_FLAG)
		ft_printf("sb\n");
	*head = second;
	return 1;
}

int	swap_both(t_stack **a_stack, t_stack **b_stack)
{
	list_swap(a_stack, NULL_FLAG);
	list_swap(b_stack, NULL_FLAG);
	ft_printf("ss\n");
	return 1;
}

int	push_b(t_stack **a_stack, t_stack **b_stack)
{
	t_stack *prev_a;

	(void)b_stack;
	prev_a = (*a_stack)->prev;
	list_swap(a_stack, &prev_a);
	ft_printf("pb\n");
	return 1;
}

int	push_a(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*a_first;
	t_stack	*b_first;
	t_stack	*b_second;

	b_first = *b_stack;
	b_second = b_first->prev;
	a_first = *a_stack;
	if (!a_first)
	{
		a_first = b_first;
		a_first->prev = NULL;
	}
	else
	{
		b_first->prev = a_first;
		a_first->next = b_first;
		a_first = b_first;
	}
	b_second->next = NULL;
	*b_stack = b_second;
	*a_stack = a_first;
	ft_printf("pa\n");
	return 1;
}