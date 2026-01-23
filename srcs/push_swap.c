/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 21:45:23 by eturini           #+#    #+#             */
/*   Updated: 2026/01/23 11:31:42 by eturini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_stack **a_stack, t_stack **b_stack)
{
	if (stack_size(*a_stack) <= 3)
		sort_three(a_stack);
	if (is_sorted(*a_stack) == TRUE || stack_size(*a_stack) == 1)
		return ;
	while (stack_size(*a_stack) > 3)
		execute_move(a_stack, b_stack);
	sort_three(a_stack);
	while (stack_size(*b_stack) != 0)
		sort_back(a_stack, b_stack);
	final_rotate(a_stack);
}

int	main(int argc, char **argv)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	long	*arguments;

	a_stack = NULL;
	b_stack = NULL;
	if (argc == 1)
		return (0);
	if (check_input_validity(argc, argv, &arguments) == FALSE)
		return (put_error());
	if (!setup_a(&a_stack, arguments, count_arguments(argv)))
		return (put_error());
	index_sorting(&a_stack, arguments);
	push_swap(&a_stack, &b_stack);
	free(arguments);
	free_stack(a_stack);
	free_stack(b_stack);
	return (0);
}
