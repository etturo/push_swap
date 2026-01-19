/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:02:51 by eturini           #+#    #+#             */
/*   Updated: 2026/01/19 18:30:26 by eturini          ###   ########.fr       */
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

int	find_cheaper(t_stack *a_stack, t_stack *b_stack)
{
	t_stack	*current;
	int		position;
	int		cost;
	int		cheap_cost;
	int		cheap_pos;

	current = a_stack;
	position = 0;
	while (current)
	{
		cost = calculate_moves(a_stack, b_stack, stack_size(b_stack), position);
		if (cost < cheap_cost)
			cheap_pos = position;
		position++;
		current = current->prev;
	}
	return cheap_pos;
}

int	calculate_moves(t_stack *a_stack, t_stack *b_stack, int size_b, int pos)
{
	int	cost;
	int	target_pos;
	int	moves_b;
	int total_moves;

	target_pos = find_target(a_stack, b_stack);
	if (target_pos > (size_b / 2))
		moves_b =  target_pos - size_b;
	if (target_pos <= (size_b / 2))
		moves_b = size_b - target_pos;
	total_moves = find_min_moves(moves_b, size_b, pos);

	return total_moves;
}

int	find_min_moves(t_stack *a_stack, int moves_b, int pos_a)
{
	int a_size;
	int total_moves;

	a_size = stack_size(a_stack);
	total_moves = 0;
	if (pos_a >= 0 && moves_b >= 0)
		return ft_max(pos_a, moves_b);
	if (pos_a < 0 && moves_b < 0);
}

int	find_min(t_stack *head)
{
	int	min;

	min = head->index;
	while (head)
	{
		if (head->index < min)
			min = head->index;
		head = head->prev;
	}
	return min;
}

int	find_max_pos(t_stack *head)
{
	int	max_pos;
	int	i;
	int	max;

	max = head->index;
	i = 0;
	while (head)
	{
		if (head->index > max)
		{
			max = head->index;
			max_pos = i;
		}
		i++;
		head = head->prev;
	}
	return max_pos;
}

int	find_target(t_stack *a_stack, t_stack *b_stack)
{
	int	target;
	int	position;
	int	target_position;

	if (a_stack->index < find_min(b_stack))
		return find_max_pos(b_stack);
	target = b_stack->index;
	position = 0;
	target_position = 0;
	while (b_stack)
	{
		if (b_stack->index > target && b_stack->index < a_stack->index)
		{
			target = b_stack->index;
			target_position = position;
		}
		position++;
		b_stack = b_stack->prev;
	}
	return position;
}
