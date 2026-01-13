/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 21:45:23 by eturini           #+#    #+#             */
/*   Updated: 2026/01/13 18:36:18 by eturini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap()
{
	
}

int main(int argc, char **argv)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	long long	*arguments;

	a_stack = NULL;
	b_stack = NULL;
	if (check_input_validity(argc, argv, &arguments) == FALSE)
		return (put_error());
	printf("ARGUMENTS IN ARRAY\n");
	for(int i = 0; arguments[i] != END_VALUE; i++)
		printf("%lld ", arguments[i]);
	printf("\n");
	if (!setup_a(&a_stack, arguments) || !setup_b(&b_stack))
		return(put_error());
	printf("ARGUMENTS IN STACK\n");
	t_stack *current = a_stack;
	while (current != NULL)
	{
		printf("%d ", current->value);
		current = current->prev;
	}
	printf("\n");
	return 0;
}
