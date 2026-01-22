/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:47:14 by eturini           #+#    #+#             */
/*   Updated: 2026/01/22 14:32:07 by eturini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	execute_check(char *op, t_stack **a_stack, t_stack **b_stack)
{
	if (ft_strncmp(op, "sa", 3) == TRUE)
		swap(a_stack);
	else if (ft_strncmp(op, "sb", 3) == TRUE)
		swap(b_stack);
	else if (ft_strncmp(op, "ss", 3) == TRUE)
		swap_both(a_stack, b_stack);
	else if (ft_strncmp(op, "pa", 3) == TRUE)
		push_a(a_stack, b_stack);
	else if (ft_strncmp(op, "pb", 3) == TRUE)
		push_b(a_stack, b_stack);
	else if (ft_strncmp(op, "ra", 3) == TRUE)
		rotate(a_stack);
	else if (ft_strncmp(op, "rb", 3) == TRUE)
		rotate(b_stack);
	else if (ft_strncmp(op, "rr", 3) == TRUE)
		rotate_both(a_stack, b_stack);
	else if (ft_strncmp(op, "rra", 3) == TRUE)
		reverse_rotate(a_stack);
	else if (ft_strncmp(op, "rrb", 3) == TRUE)
		reverse_rotate(b_stack);
	else if (ft_strncmp(op, "rrr", 3) == TRUE)
		reverse_rotate_both(a_stack, b_stack);
}

int	is_sorted(t_stack *stack)
{
	t_stack	*current;

	if (!stack || !stack->prev)
		return (TRUE);
	current = stack;
	while (current->prev)
	{
		if (current->index > current->prev->index)
			return (FALSE);
		current = current->prev;
	}
	return (TRUE);
}

void	checker(t_stack **a_stack, t_stack **b_stack)
{
	char	buf[1];
	char	op[4];
	int		i;

	while (read(0, buf, 1) > 0)
	{
		i = 0;
		if (buf[0] == '\n')
			continue ;
		op[0] = buf[0];
		while (op[0] != '\n' && i < 3)
		{
			i++;
			if (read(0, buf, 1) <= 0)
				break ;
			op[i] = buf[0];
		}
		op[i] = '\0';
		execute_check(op, a_stack, b_stack);
	}
	if (is_sorted(*a_stack) == TRUE)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
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
