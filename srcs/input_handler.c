/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:35:56 by eturini           #+#    #+#             */
/*   Updated: 2026/01/02 20:15:56 by eturini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_input_validity(int argc, char **argv, int **arguments)
{
	int	i;

	if (argc <= 1)
		return FALSE;
	*arguments = (int *)malloc(sizeof(int) * argc);
	if (!*arguments)
		return FALSE;
	i = 0;
	while (++i < argc)
		*arguments[i - 1] = ft_atoi(argv[i]);
	i = 0;
	while (++i < argc)
		printf("%d, ", *arguments[i]);
	printf("\n");
	return (TRUE);
}
