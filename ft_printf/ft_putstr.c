/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 20:50:56 by ettore            #+#    #+#             */
/*   Updated: 2025/12/06 18:54:13 by eturini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s, int *count)
{
	if (!s)
		return (ft_putstr("(null)", count));
	while (*s != 0)
	{
		write(1, s, 1);
		(*count)++;
		s++;
	}
	return (TRUE);
}
