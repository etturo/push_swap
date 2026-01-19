/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:35:56 by eturini           #+#    #+#             */
/*   Updated: 2026/01/19 15:26:02 by eturini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_input_validity(int argc, char **argv, long **arguments)
{
	int	count_arg;
	int	i;

	if (argc <= 1)
		return FALSE;
	if (check_arg(argv) == FALSE)
		return FALSE;
	count_arg = count_arguments(argv);
	*arguments = (long *)malloc((sizeof(long) * (count_arg + 1)));
	if (!*arguments)
		return FALSE;
	if (fill_the_arguments(argv, arguments) == FALSE)
		return FALSE;
	i = count_arg;
	while (--i >= 0)
		if ((*arguments)[i] > INT_MAX || (*arguments)[i] < INT_MIN)
			return (FALSE);
	if (check_dup(*arguments, count_arg) == FALSE)
		return FALSE;
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

int	fill_the_arguments(char **argv, long **arguments)
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
				(*arguments)[ar_index] = ft_atoi(&(argv[i][j]));
				if ((*arguments)[ar_index++] == ERROR_FLAG)
					return FALSE;
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

int	check_dup(long *arguments, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arguments[i] == arguments[j])
				return FALSE;
			j++;
		}
		i++;
	}
	return TRUE;
}
