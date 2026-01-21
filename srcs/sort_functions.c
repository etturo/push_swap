/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:27:59 by eturini           #+#    #+#             */
/*   Updated: 2026/01/21 14:29:03 by eturini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sort_two(t_stack **a_stack)
{
	if (stack_size(*a_stack) == 1 || stack_size(*a_stack) == 0)
		return (0);
	if ((*a_stack)->index > (*a_stack)->prev->index)
		return (swap(a_stack, A_FLAG));
	return (0);
}

int	sort_three(t_stack **a_stack)
{
	int		count;
	int		n[3];

	count = 0;
	if (stack_size(*a_stack) < 3)
		return (sort_two(a_stack));
	n[0] = (*a_stack)->index;
	n[1] = (*a_stack)->prev->index;
	n[2] = (*a_stack)->prev->prev->index;
	count = 0;
	if (n[0] < n[1] && n[1] > n[2] && n[0] < n[2])
		return (swap(a_stack, A_FLAG) + rotate(a_stack, A_FLAG));
	if (n[0] > n[1] && n[1] < n[2] && n[0] < n[2])
		return (swap(a_stack, A_FLAG));
	if (n[0] < n[1] && n[1] > n[2] && n[0] > n[2])
		return (reverse_rotate(a_stack, A_FLAG));
	if (n[0] > n[1] && n[1] > n[2] && n[0] > n[2])
		return (swap(a_stack, A_FLAG) + reverse_rotate(a_stack, A_FLAG));
	if (n[0] > n[1] && n[1] < n[2] && n[0] > n[2])
		return (rotate(a_stack, A_FLAG));
	return (count);
}

int	is_sorted(t_stack *stack)
{
	t_stack	*current;

	if (!stack || !stack->prev)
		return (TRUE);
	current = stack;
	while (current->prev)
	{
		if (current->index > current->prev->index)
			return (FALSE);
		current = current->prev;
	}
	return (TRUE);
}

void	index_sorting(t_stack **stack, long *arguments)
{
	t_stack	*current;
	int		size;
	int		i;

	size = stack_size(*stack);
	arguments = bubble_sort(arguments, size);
	current = *stack;
	if (size <= 1)
		return ;
	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (current->value == arguments[i])
			{
				current->index = i;
				break ;
			}
			i++;
		}
		current = current->prev;
	}
}

long	*bubble_sort(long *num, int size)
{
	int		i;
	long	temp;

	if (size <= 1)
		return (NULL);
	i = 1;
	while (i < size)
	{
		if (num[i - 1] > num[i])
		{
			temp = num[i - 1];
			num[i - 1] = num[i];
			num[i] = temp;
			i = 1;
		}
		else
			i++;
	}
	return (num);
}
