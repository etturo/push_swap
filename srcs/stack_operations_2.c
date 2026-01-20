/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:49:52 by eturini           #+#    #+#             */
/*   Updated: 2026/01/20 21:45:06 by eturini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rotate(t_stack **head, int flag)
{
	t_stack	*last;
	t_stack	*temp;

	if (!*head || !(*head)->prev)
		return 1;
	temp = (*head)->prev;
	last = *head;
	while (last->prev)
		last = last->prev;
	((*head)->prev)->next = NULL;
	(*head)->prev = NULL;
	(*head)->next = last;
	last->prev = *head;
	*head = temp;
	if (flag == A_FLAG)
		ft_printf("ra\n");
	if (flag == B_FLAG)
		ft_printf("rb\n");
	return 1;
}

int	rotate_both(t_stack **a_stack, t_stack **b_stack)
{
	rotate(a_stack, NULL_FLAG);
	rotate(b_stack, NULL_FLAG);
	ft_printf("rr\n");
	return 1;
}

int	reverse_rotate(t_stack **head, int flag)
{
	t_stack	*last;
	
	if (!*head || !(*head)->prev)
		return 1;
	last = *head;
	while (last->prev)
		last = last->prev;
	(last->next)->prev = NULL;
	last->next = NULL;
	last->prev = *head;
	(*head)->next = last;
	*head = last;
	if (flag == A_FLAG)
		ft_printf("rra\n");
	if (flag == B_FLAG)
		ft_printf("rrb\n");
	return 1;
}

int	reverse_rotate_both(t_stack **a_stack, t_stack **b_stack)
{
	reverse_rotate(a_stack, NULL_FLAG);
	reverse_rotate(b_stack, NULL_FLAG);
	ft_printf("rrr\n");
	return 1;
}

