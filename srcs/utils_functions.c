/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:23:28 by eturini           #+#    #+#             */
/*   Updated: 2026/01/16 11:48:23 by eturini          ###   ########.fr       */
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

