/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:23:28 by eturini           #+#    #+#             */
/*   Updated: 2026/01/15 16:07:33 by eturini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	ft_atoi(const char *s)
{
	int			sign;
	int			i;
	long	number;

	sign = 1;
	i = 0;
	number = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		number = number * 10 + (s[i] - '0');
		i++;
	}
	return ((long)(number * sign));
}

void free_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*prev;

	current = stack;
	while (current)
	{
		prev = current->prev;
		free(current);
		current = prev;
	}
}

void	list_swap(t_stack **ele1, t_stack **ele2)
{
	t_stack	*prev1;
	t_stack	*prev2;

	if (!*ele1)
	{
		*ele1 = *ele2;
		*ele2 = NULL;
	}
	if (!*ele2)
	{
		*ele2 = *ele1;
		*ele1 = NULL;
	}
	prev1 = (*ele1)->prev;
	prev2 = (*ele2)->prev;
	prev1->next = *ele1;
	prev2->next = *ele2;
	(*ele1)->prev = *ele2;
	(*ele2)->prev = *ele1;
}
