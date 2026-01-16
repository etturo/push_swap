/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 21:45:23 by eturini           #+#    #+#             */
/*   Updated: 2026/01/16 12:47:35 by eturini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_stack **a_stack, t_stack **b_stack)
{
	int	count;

	(void)b_stack;
	count = 0;
	// count += rotate(a_stack, A_FLAG);
	// count += rotate(a_stack, A_FLAG);
	// count += rotate(a_stack, A_FLAG);
	// count += reverse_rotate(a_stack, A_FLAG);
	// count += reverse_rotate(a_stack, A_FLAG);
	// count += push_b(a_stack, b_stack);
	// count += push_b(a_stack, b_stack);
	// count += push_b(a_stack, b_stack);
	// count += rotate(b_stack, B_FLAG);
	// count += swap_both(a_stack, b_stack);
	// count += push_a(a_stack, b_stack);
	// count += swap_both(a_stack, b_stack);
	// count += push_b(a_stack, b_stack);
	// count += push_b(a_stack, b_stack);
	// count += reverse_rotate_both(a_stack, b_stack);
	// count += reverse_rotate_both(a_stack, b_stack);
	// count += push_b(a_stack, b_stack);
	// count += push_b(a_stack, b_stack);
	// count += push_b(a_stack, b_stack);
	// count += push_b(a_stack, b_stack);
	// count += push_b(a_stack, b_stack);
	// count += push_b(a_stack, b_stack);
	// count += swap_both(a_stack, b_stack);
	// count += push_a(a_stack, b_stack);
	// count += push_a(a_stack, b_stack);
	// count += push_a(a_stack, b_stack);
	// count += push_a(a_stack, b_stack);
	// count += push_a(a_stack, b_stack);
	ft_printf("number of operation: %d\n", count);
}

int main(int argc, char **argv)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	long	*arguments;

	//temp variables
	t_stack	*current;

	ft_printf("\n");
	a_stack = NULL;
	b_stack = NULL;
	(void)b_stack;
	if (check_input_validity(argc, argv, &arguments) == FALSE)
		return (put_error());
	if (!setup_a(&a_stack, arguments))
		return(put_error());
	ft_printf("------------------------------------------\n");
	ft_printf("BEFORE PUSH_SWAP\nSTACK A: ");
	current = a_stack;
	while (current)
	{
		ft_printf("%d ", current->value);
		current = current->prev;
	}
	ft_printf("\nSTACK B: ");
	current = b_stack;
	while (current)
	{
		ft_printf("%d ", current->value);
		current = current->prev;
	}
	ft_printf("\n");
	ft_printf("------------------------------------------\n");
	push_swap(&a_stack, &b_stack);
	ft_printf("------------------------------------------\n");
	ft_printf("AFTER PUSH_SWAP\nSTACK A: ");
	current = a_stack;
	while (current)
	{
		ft_printf("%d ", current->value);
		current = current->prev;
	}
	ft_printf("\nSTACK B: ");
	current = b_stack;
	while (current)
	{
		ft_printf("%d ", current->value);
		current = current->prev;
	}
	free(arguments);
	free_stack(a_stack);
	free_stack(b_stack);
	ft_printf("\n");
	ft_printf("------------------------------------------\n");
	return 0;
}
