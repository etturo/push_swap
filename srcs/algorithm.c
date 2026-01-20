/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:02:51 by eturini           #+#    #+#             */
/*   Updated: 2026/01/20 18:27:12 by eturini          ###   ########.fr       */
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
		if (prev > current->value)
			return FALSE;
		prev = current->value;
		current = current->prev;
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

int sort_three(t_stack **a_stack)
{
	int		count;
	int		n[3];

	count = 0;
	n[0] = (*a_stack)->index;
	n[1] = (*a_stack)->prev->index;
	n[2] = (*a_stack)->prev->prev->index;
	count = 0;
	if (n[0] < n[1] && n[1] > n[2] && n[0] < n[2])
		return swap(a_stack, A_FLAG) + rotate(a_stack, A_FLAG);
	if (n[0] > n[1] && n[1] < n[2] && n[0] < n[2])
		return swap(a_stack, A_FLAG);
	if (n[0] < n[1] && n[1] > n[2] && n[0] > n[2])
		return reverse_rotate(a_stack, A_FLAG);
	if (n[0] > n[1] && n[1] > n[2] && n[0] > n[2])
		return swap(a_stack, A_FLAG) + reverse_rotate(a_stack, A_FLAG);
	if (n[0] > n[1] && n[1] < n[2] && n[0] > n[2])
		return rotate(a_stack, A_FLAG);
	return count;
}

int	execute_move(t_stack **a_stack, t_stack **b_stack)
{
	t_moves	moves;
	int		count;

	count = 0;
	find_cheaper(*a_stack, *b_stack, &moves);
	while (moves.ra > 0 && moves.rb > 0)
	{
		count += rotate_both(a_stack, b_stack);
		moves.ra--;
		moves.rb--;
	}
	while (moves.ra < 0 && moves.rb < 0)
	{
		count += reverse_rotate_both(a_stack, b_stack);
		moves.ra++;
		moves.rb++;
	}
	while (moves.ra > 0 && moves.ra--)
		count += rotate(a_stack, A_FLAG);
	while (moves.ra < 0 && moves.ra++)
		count += reverse_rotate(a_stack, A_FLAG);
	while (moves.rb > 0 && moves.rb--)
		count += rotate(b_stack, B_FLAG);
	while (moves.rb < 0 && moves.rb++)
		count += reverse_rotate(b_stack, B_FLAG);
	count += push_b(a_stack, b_stack);
	return (count);
}

int	find_cheaper(t_stack *a_stack, t_stack *b_stack, t_moves *moves)
{
	t_stack	*current;
	int		position;
	int		cost;
	int		cheap_cost;
	int		cheap_pos;

	current = a_stack;
	position = 0;
	cheap_cost = 1000000;
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
	return cheap_pos;
}

int	calculate_moves(t_stack *a_stack, t_stack *b_stack, int a_pos, t_moves *move)
{
	int	target_pos;
	int moves[4];
	int comb[4];

	target_pos = find_target(a_stack, b_stack, a_pos);
	moves[0] = a_pos;
	moves[1] = a_pos - stack_size(a_stack);
	moves[2] = target_pos;
	moves[3] = target_pos - stack_size(b_stack);
	comb[0] = ft_max(moves[0], moves[2]);
	comb[1] = moves[0] + ft_abs(moves[2]);
	comb[2] = ft_abs(moves[1]) + moves[2];
	comb[3] = ft_max(ft_abs(moves[1]), ft_abs(moves[3]));
	return find_min_moves(moves, comb, move);
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
	return min;
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

int	find_max(t_stack *head)
{
	int	max;

	max = head->index;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->prev;
	}
	return max;
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
	return max_pos;
}

int	find_target(t_stack *a_stack, t_stack *b_stack, int a_pos)
{
	int	target;
	int	position;
	int	target_position;

	while (a_pos-- > 0)
		a_stack = a_stack->prev;
	if (a_stack->index < find_min(b_stack))
		return find_max_pos(b_stack);
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
	return target_position;
}

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

int	find_n_rotation(t_stack *a_stack, int value)
{
	int		n;
	t_stack	*prev;
	t_stack	*current;

	if (value < find_min(a_stack) || value > find_max(a_stack))
		return find_min_pos(a_stack);
	n = 0;
	current = a_stack;
	while (current->prev)
	{
		prev = current->prev;
		if (value < current->index && value > prev->index)
			return (n + 1);
		current = current->prev;
		n++;
	}
	if (current->index < value && a_stack->index > value)
		return 0;
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
	return count;
}
