/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:21:37 by eturini           #+#    #+#             */
/*   Updated: 2026/01/14 18:31:56 by eturini          ###   ########.fr       */
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
	swap(a_stack, NULL_FLAG);
	swap(b_stack, NULL_FLAG);
	ft_printf("ss\n");
	return 1;
}