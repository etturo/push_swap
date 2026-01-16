/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:38:49 by eturini           #+#    #+#             */
/*   Updated: 2025/12/08 17:21:12 by eturini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0
# define HEX_LOW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"

int	ft_printf(const char *format, ...);
int	handle_format(char *s, va_list argptr, int *count);
int	ft_putstr(char *s, int *count);
int	ft_putnbr(int n, int *count);
int	ft_putnbr_u(unsigned int n, int *count);
int	ft_putnbr_ptr(unsigned long long nbr, char *base, int *count,
		int prefix);
int	ft_putnbr_hex(unsigned int nbr, char *base, int *count);
int	ft_putchar(char c, int *count);

#endif