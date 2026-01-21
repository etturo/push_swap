/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:00:00 by eturini           #+#    #+#             */
/*   Updated: 2026/01/21 17:10:51 by eturini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

long	ft_atoi(const char *s)
{
	int			sign;
	int			i;
	long		number;

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
		if (number > INT_MAX || number < INT_MIN)
			return (ERROR_FLAG);
	}
	return ((long)(number * sign));
}

void	free_stack(t_stack *stack)
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

int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->prev;
	}
	return (count);
}

int	skip_number(char *s)
{
	int	j;

	j = 0;
	while ((s[j] >= '0' && s[j] <= '9') || s[j] == '+' || s[j] == '-')
		j++;
	return (j);
}

int	is_number(char c)
{
	if ((c >= '0' && c <= '9') || c == '+' || c == '-')
		return (TRUE);
	return (FALSE);
}
