/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 21:45:23 by eturini           #+#    #+#             */
/*   Updated: 2026/01/20 18:29:26 by eturini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_stack **a_stack, t_stack **b_stack, long *arguments)
{
	int	count;

	(void)b_stack;
	(void)arguments;
	count = 0;
	if (stack_size(*a_stack) == 3)
		sort_three(a_stack);
	if (is_sorted(*a_stack) == TRUE)
		return ;
	count += push_b(a_stack, b_stack);
	count += push_b(a_stack, b_stack);
	/*-----------------------AREA TEST--------------------------------*/

	while (stack_size(*a_stack) > 3)
		count += execute_move(a_stack, b_stack);
	count += sort_three(a_stack);
	while (stack_size(*b_stack) != 0)
		count += sort_back(a_stack, b_stack);
	

	/*----------------------------------------------------------------*/
	printf("number of operation: %d\n", count);
}

int main(int argc, char **argv)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	long	*arguments;

	//temp variables
	t_stack	*current;

	ft_printf("\n");
	ft_printf("------------------------------------------------------\n");
	ft_printf("ARGUMENTS: ");
	for (int i = 1; i < argc; i++)
		ft_printf("%s ", argv[i]);
	ft_printf("\n");

	a_stack = NULL;
	b_stack = NULL;
	(void)b_stack;
	if (check_input_validity(argc, argv, &arguments) == FALSE)
		return (put_error());
	if (!setup_a(&a_stack, arguments, count_arguments(argv)))
		return(put_error());

	index_sorting(&a_stack, arguments);
	current = a_stack;
	ft_printf("------------------------------------------------------\n");
	ft_printf("INDEXED: ");
	while (current)
	{
		ft_printf("%d ", current->index);
		current = current->prev;
	}
	ft_printf("\n");

	ft_printf("------------------------------------------------------\n");
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
	ft_printf("------------------------------------------------------\n");
	push_swap(&a_stack, &b_stack, arguments);
	ft_printf("------------------------------------------------------\n");
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
	ft_printf("------------------------------------------------------\n");
	return 0;
}
