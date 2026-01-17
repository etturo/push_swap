/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:02:51 by eturini           #+#    #+#             */
/*   Updated: 2026/01/17 18:00:11 by eturini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*current;
	int		prev;

	current = stack;
	prev = current->value;
	while (current->prev)
	{
		current = current->prev;
		if (prev < current->value)
			return FALSE;
	}
	return TRUE;
}

long	*bubble_sort(long *num, int size)
{
	int		i;
	long	temp;

	if (size <= 1)
		return NULL;
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
	return num;
}

void	index_sorting(t_stack **stack, long *arguments)
{
	t_stack	*current;
	int		size;
	int		i;

	size = stack_size(*stack);
	arguments = bubble_sort(arguments, size);
	current = *stack;
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
