/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 21:45:23 by eturini           #+#    #+#             */
/*   Updated: 2025/12/27 00:09:31 by eturini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(void)
{
	t_stack	*a_stack;
	t_stack	*b_stack;

	a_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!a_stack)
		return ;
	b_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!b_stack)
		return ;
	setup_a_stack(a_stack);
	setup_b_stack(b_stack);
}

int main(int argc, char **argv)
{
	push_swap();
	return 0;
}
