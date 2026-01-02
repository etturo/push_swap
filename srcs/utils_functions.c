/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:23:28 by eturini           #+#    #+#             */
/*   Updated: 2026/01/02 17:08:09 by eturini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*new_s;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_s = malloc(len1 + len2 + 1);
	i = 0;
	if (!new_s)
		return ((void *)0);
	while (i < len1)
	{
		new_s[i] = s1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		new_s[i] = s2[i - len1];
		i++;
	}
	new_s[len1 + len2] = '\0';
	return (new_s);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_atoi(const char *s)
{
	int			sign;
	int			i;
	long int	number;

	sign = 1;
	i = 0;
	number = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		number = number * 10 + (s[i] - '0');
		i++;
	}
	return ((int)(number * sign));
}
