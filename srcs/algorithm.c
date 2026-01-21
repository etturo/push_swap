/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:02:51 by eturini           #+#    #+#             */
/*   Updated: 2026/01/21 14:33:22 by eturini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	execute_move(t_stack **a_stack, t_stack **b_stack)
{
	t_moves	moves;

	find_cheaper(*a_stack, *b_stack, &moves);
	while (moves.ra > 0 && moves.rb > 0)
	{
		rotate_both(a_stack, b_stack);
		moves.ra--;
		moves.rb--;
	}
	while (moves.ra < 0 && moves.rb < 0)
	{
		reverse_rotate_both(a_stack, b_stack);
		moves.ra++;
		moves.rb++;
	}
	while (moves.ra > 0 && moves.ra--)
		rotate(a_stack, A_FLAG);
	while (moves.ra < 0 && moves.ra++)
		reverse_rotate(a_stack, A_FLAG);
	while (moves.rb > 0 && moves.rb--)
		rotate(b_stack, B_FLAG);
	while (moves.rb < 0 && moves.rb++)
		reverse_rotate(b_stack, B_FLAG);
	push_b(a_stack, b_stack);
	return (TRUE);
}

int	calculate_moves(t_stack *a_stack, t_stack *b_stack, int a_pos,
		t_moves *move)
{
	int	target_pos;
	int	moves[4];
	int	comb[4];

	target_pos = find_target(a_stack, b_stack, a_pos);
	moves[0] = a_pos;
	moves[1] = a_pos - stack_size(a_stack);
	moves[2] = target_pos;
	moves[3] = target_pos - stack_size(b_stack);
	comb[0] = ft_max(moves[0], moves[2]);
	comb[1] = moves[0] + ft_abs(moves[3]);
	comb[2] = ft_abs(moves[1]) + moves[2];
	comb[3] = ft_max(ft_abs(moves[1]), ft_abs(moves[3]));
	return (find_min_moves(moves, comb, move));
}

int	find_n_rotation(t_stack *a_stack, int value)
{
	int		n;
	t_stack	*prev;
	t_stack	*current;

	if (value < find_min(a_stack) || value > find_max(a_stack))
		return (find_min_pos(a_stack));
	n = 0;
	current = a_stack;
	while (current->prev)
	{
		prev = current->prev;
		if (value > current->index && value < prev->index)
			return (n + 1);
		current = current->prev;
		n++;
	}
	if (current->index < value && a_stack->index > value)
		return (0);
	return (find_min_pos(a_stack));
}

int	sort_back(t_stack **a_stack, t_stack **b_stack)
{
	int		count;
	int		n;
	int		size;

	count = 0;
	size = stack_size(*a_stack);
	n = find_n_rotation(*a_stack, (*b_stack)->index);
	if (n <= size / 2)
		while (n-- > 0)
			count += rotate(a_stack, A_FLAG);
	else
		while (n++ < size)
			count += reverse_rotate(a_stack, A_FLAG);
	count += push_a(a_stack, b_stack);
	return (count);
}

void	final_rotate(t_stack **a_stack)
{
	int	min_pos;
	int	size;

	min_pos = find_min_pos(*a_stack);
	size = stack_size(*a_stack);
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			rotate(a_stack, A_FLAG);
	}
	else
	{
		while (min_pos++ < size)
			reverse_rotate(a_stack, A_FLAG);
	}
}
