/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 17:36:24 by eturini           #+#    #+#             */
/*   Updated: 2025/12/08 17:20:58 by eturini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_format(char *s, va_list argptr, int *count)
{
	if (*s == 'c')
		return (ft_putchar(va_arg(argptr, int), count));
	if (*s == 's')
		return (ft_putstr(va_arg(argptr, char *), count));
	if (*s == 'p')
		return (ft_putnbr_ptr(va_arg(argptr, unsigned long long), HEX_LOW,
				count, 1));
	if (*s == 'd' || *s == 'i')
		return (ft_putnbr(va_arg(argptr, int), count));
	if (*s == 'u')
		return (ft_putnbr_u(va_arg(argptr, unsigned int), count));
	if (*s == 'x')
		return (ft_putnbr_hex(va_arg(argptr, int), HEX_LOW, count));
	if (*s == 'X')
		return (ft_putnbr_hex(va_arg(argptr, int), HEX_UP, count));
	if (*s == '%')
		return (ft_putchar('%', count));
	return (FALSE);
}

int	ft_printf(const char *format, ...)
{
	va_list	argptr;
	char	*s;
	int		count;

	va_start(argptr, format);
	s = (char *)format;
	count = 0;
	while (*s != '\0')
	{
		if (*s == '%' && handle_format(s + 1, argptr, &count) != FALSE)
			s += 2;
		else
			ft_putchar(*(s++), &count);
	}
	va_end(argptr);
	return (count);
}
