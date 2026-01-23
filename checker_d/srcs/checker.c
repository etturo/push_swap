/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:47:14 by eturini           #+#    #+#             */
/*   Updated: 2026/01/23 16:38:00 by eturini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	execute_check(char *op, t_stack **a_stack, t_stack **b_stack)
{
	if (ft_strncmp(op, "sa", 3) == TRUE)
		return (swap(a_stack));
	else if (ft_strncmp(op, "sb", 3) == TRUE)
		return (swap(b_stack));
	else if (ft_strncmp(op, "ss", 3) == TRUE)
		return (swap_both(a_stack, b_stack));
	else if (ft_strncmp(op, "pa", 3) == TRUE)
		return (push_a(a_stack, b_stack));
	else if (ft_strncmp(op, "pb", 3) == TRUE)
		return (push_b(a_stack, b_stack));
	else if (ft_strncmp(op, "ra", 3) == TRUE)
		return (rotate(a_stack));
	else if (ft_strncmp(op, "rb", 3) == TRUE)
		return (rotate(b_stack));
	else if (ft_strncmp(op, "rr", 3) == TRUE)
		return (rotate_both(a_stack, b_stack));
	else if (ft_strncmp(op, "rra", 3) == TRUE)
		return (reverse_rotate(a_stack));
	else if (ft_strncmp(op, "rrb", 3) == TRUE)
		return (reverse_rotate(b_stack));
	else if (ft_strncmp(op, "rrr", 3) == TRUE)
		return (reverse_rotate_both(a_stack, b_stack));
	return (FALSE);
}

int	is_sorted(t_stack *stack)
{
	t_stack	*current;

	if (!stack || !stack->prev)
		return (TRUE);
	current = stack;
	while (current->prev)
	{
		if (current->value > current->prev->value)
			return (FALSE);
		current = current->prev;
	}
	return (TRUE);
}

int	checker(t_stack **a_stack, t_stack **b_stack)
{
	char	buf;
	char	op[5];
	int		i;

	i = 0;
	while (read(0, &buf, 1) > 0)
	{
		if (buf == '\n')
		{
			op[i] = '\0';
			if (i > 0 && execute_check(op, a_stack, b_stack) == FALSE)
				return (put_error());
			i = 0;
		}
		else if (i < 4)
			op[i++] = buf;
	}
	if (is_sorted(*a_stack) == TRUE && stack_size(*b_stack) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	long	*arguments;

	a_stack = NULL;
	b_stack = NULL;
	if (check_input_validity(argc, argv, &arguments) == FALSE)
		return (put_error());
	if (!setup_a(&a_stack, arguments, count_arguments(argv)))
		return (put_error());
	checker(&a_stack, &b_stack);
	free(arguments);
	free_stack(a_stack);
	free_stack(b_stack);
	return (0);
}
