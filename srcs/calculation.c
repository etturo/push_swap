/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:29:32 by eturini           #+#    #+#             */
/*   Updated: 2026/01/21 14:33:29 by eturini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_cheaper(t_stack *a_stack, t_stack *b_stack, t_moves *moves)
{
	t_stack	*current;
	int		position;
	int		cost;
	int		cheap_cost;
	int		cheap_pos;

	current = a_stack;
	cheap_pos = 0;
	position = 0;
	cheap_cost = INT_MAX;
	while (current)
	{
		cost = calculate_moves(a_stack, b_stack, position, moves);
		if (cost < cheap_cost)
		{
			cheap_cost = cost;
			cheap_pos = position;
		}
		position++;
		current = current->prev;
	}
	cost = calculate_moves(a_stack, b_stack, cheap_pos, moves);
	return (cheap_pos);
}

int	find_min_moves(int *move, int *comb, t_moves *moves)
{
	int	min;
	int	i;

	min = comb[0];
	set_moves(move, moves, 0);
	i = 1;
	while (i < 4)
	{
		if (min > comb[i])
		{
			set_moves(move, moves, i);
			min = comb[i];
		}
		i++;
	}
	return (min);
}

int	find_min(t_stack *head)
{
	int	min;

	if (!head)
		return (0);
	min = head->index;
	while (head)
	{
		if (head->index < min)
			min = head->index;
		head = head->prev;
	}
	return (min);
}

int	find_max(t_stack *head)
{
	int	max;

	if (!head)
		return (0);
	max = head->index;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->prev;
	}
	return (max);
}

int	find_max_pos(t_stack *head)
{
	int	max_pos;
	int	i;
	int	max;

	max = head->index;
	max_pos = 0;
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
	return (max_pos);
}
