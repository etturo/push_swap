/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:35:56 by eturini           #+#    #+#             */
/*   Updated: 2026/01/13 17:39:43 by eturini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_input_validity(int argc, char **argv, long long **arguments)
{
	int	count_arg;

	if (argc <= 1 || !*arguments)
		return FALSE;
	if (check_arg(argv) == FALSE)
		return FALSE;
	count_arg = count_arguments(argv);
	*arguments = (long long *)malloc((sizeof(long long) * count_arg) + 1);
	if (!*arguments)
		return FALSE;
	if (fill_the_arguments(argv, arguments) == FALSE)
		return FALSE;
	(*arguments)[count_arg] = END_VALUE;
	while (--count_arg >= 0)
		if ((*arguments)[count_arg] > INT_MAX || (*arguments)[count_arg] < INT_MIN)
			return (FALSE);
	return TRUE;
}

int	count_arguments(char **argv)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j])
		{
			while (argv[i][j] == ' ' || argv[i][j] == '+' || argv[i][j] == '-')
				j++;
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
			{
				count++;
				while (argv[i][j] >= '0' && argv[i][j] <= '9')
					j++;
			}
			else if (argv[i][j] != '\0')
				return -1;
		}
	}
	return count;
}

int	fill_the_arguments(char **argv, long long **arguments)
{
	int	i;
	int	j;
	int	ar_index;

	i = 0;
	ar_index = 0;
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j])
		{
			while (argv[i][j] == ' ')
				j++;
			if ((argv[i][j] >= '0' && argv[i][j] <= '9') || argv[i][j] == '+' || argv[i][j] == '-')
			{
				(*arguments)[ar_index++] = ft_atoi(&(argv[i][j]));
				while ((argv[i][j] >= '0' && argv[i][j] <= '9') || argv[i][j] == '+' || argv[i][j] == '-')
					j++;
			}
			else if (argv[i][j] != '\0')
				return FALSE;
		}
	}
	return TRUE;
}

int	check_arg(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j])
		{
			while (argv[i][j] == ' ')
				j++;
			if (argv[i][j] == '-' || argv[i][j] == '+')
				if (argv[i][++j] < '0' || argv[i][j] > '9')
					return FALSE;
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				while (argv[i][j] >= '0' && argv[i][j] <= '9')
					j++;
			else if (argv[i][j] != '\0' && argv[i][j] != ' ')
				return FALSE;
			if (argv[i][j] != '\0' && argv[i][j] != ' ')
				return FALSE;
		}
	}
	return TRUE;
}
