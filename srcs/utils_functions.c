/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturini <eturini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:23:28 by eturini           #+#    #+#             */
/*   Updated: 2025/12/17 23:01:50 by eturini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
