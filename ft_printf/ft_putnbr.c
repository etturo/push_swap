/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 21:33:32 by ettore            #+#    #+#             */
/*   Updated: 2025/12/06 17:58:43 by eturini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, int *count)
{
	if (n == -2147483648)
		return (ft_putstr("-2147483648", count));
	if (n < 0)
	{
		ft_putchar('-', count);
		n *= -1;
	}
	if (n >= 10)
		ft_putnbr((n / 10), count);
	ft_putchar((n % 10) + '0', count);
	return (TRUE);
}

int	ft_putnbr_u(unsigned int n, int *count)
{
	if (n >= 10)
		ft_putnbr((n / 10), count);
	ft_putchar((n % 10) + '0', count);
	return (TRUE);
}
