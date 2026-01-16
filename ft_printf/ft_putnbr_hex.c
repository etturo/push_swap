/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 18:01:58 by eturini           #+#    #+#             */
/*   Updated: 2025/12/08 16:48:18 by eturini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_ptr(unsigned long long nbr, char *base, int *count, int prefix)
{
	if (nbr == 0 && prefix == 1)
		return (ft_putstr("(nil)", count));
	if (prefix == 1)
		ft_putstr("0x", count);
	if (nbr >= 16)
		ft_putnbr_ptr((nbr / (16)), base, count, 0);
	ft_putchar(base[(nbr % 16)], count);
	return (TRUE);
}

int	ft_putnbr_hex(unsigned int nbr, char *base, int *count)
{
	if (nbr >= 16)
		ft_putnbr_hex((nbr / (16)), base, count);
	ft_putchar(base[(nbr % 16)], count);
	return (TRUE);
}
