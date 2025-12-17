/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:35:56 by eturini           #+#    #+#             */
/*   Updated: 2025/12/17 22:57:07 by eturini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_input_validity(char *arguments)
{
	(void)*arguments;
	return TRUE;
}

size_t	read_from_input(char **buffer)
{
	size_t	size;

	size = read(0, *buffer, BUFFER_SIZE);
	printf("%s\n", *buffer);
	return size;
}
