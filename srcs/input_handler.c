/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:35:56 by eturini           #+#    #+#             */
/*   Updated: 2026/01/12 18:03:21 by eturini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_input_validity(int argc, char **argv, int **arguments)
{
	int	count_arg;

	if (argc <= 1 || !*arguments)
		return FALSE;
	count_arg = count_arguments(argv);
	*arguments = (int *)malloc(sizeof(int) * count_arg);
	if (!*arguments)
		return FALSE;
	if (fill_the_arguments(argv, arguments) == FALSE)
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
			while (argv[i][j] == ' ')
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

int	fill_the_arguments(char **argv, int **arguments)
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
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
			{
				*arguments[ar_index++] = ft_atoi(&(argv[i][j]));
				while (argv[i][j] >= '0' && argv[i][j] <= '9')
					j++;
			}
			else if (argv[i][j] != '\0')
				return FALSE;
		}
	}
	return TRUE;
}
