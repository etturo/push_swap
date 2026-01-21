/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:32:29 by eturini           #+#    #+#             */
/*   Updated: 2026/01/21 14:33:36 by eturini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_min_pos(t_stack *stack)
{
	int	min_idx;
	int	min_pos;
	int	pos;

	min_idx = stack->index;
	min_pos = 0;
	pos = 0;
	while (stack)
	{
		if (stack->index < min_idx)
		{
			min_idx = stack->index;
			min_pos = pos;
		}
		pos++;
		stack = stack->prev;
	}
	return (min_pos);
}

int	find_target(t_stack *a_stack, t_stack *b_stack, int a_pos)
{
	int	target;
	int	position;
	int	target_position;

	while (a_pos-- > 0)
		a_stack = a_stack->prev;
	if (!b_stack)
		return (0);
	if (a_stack->index < find_min(b_stack))
		return (find_max_pos(b_stack));
	target = -1;
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
	return (target_position);
}

void	set_moves(int *move, t_moves *moves, int i)
{
	if (i == 0)
	{
		moves->ra = move[0];
		moves->rb = move[2];
	}
	if (i == 1)
	{
		moves->ra = move[0];
		moves->rb = move[3];
	}
	if (i == 2)
	{
		moves->ra = move[1];
		moves->rb = move[2];
	}
	if (i == 3)
	{
		moves->ra = move[1];
		moves->rb = move[3];
	}
}
