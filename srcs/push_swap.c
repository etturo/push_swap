/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 21:45:23 by eturini           #+#    #+#             */
/*   Updated: 2026/01/12 17:58:41 by eturini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap()
{
	
}

int main(int argc, char **argv)
{
	// t_stack	*a_stack;
	// t_stack	*b_stack;
	int		*arguments;

	if (check_input_validity(argc, argv, &arguments) == FALSE)
		return (put_error());
	for(int i = 0; arguments[i]; i++)
		printf("%d ", arguments[i]);
	printf("\n");
	// setup_a(a_stack, arguments);
	// setup_b(b_stack);
	// push_swap();
	return 0;
}
