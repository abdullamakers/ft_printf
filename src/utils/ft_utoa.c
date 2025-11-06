/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdualsh <abdualsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 00:33:15 by abdualsh          #+#    #+#             */
/*   Updated: 2025/11/02 02:34:57 by abdualsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*make_malloc(size_t len)
{
	char	*copy_malloc;

	copy_malloc = malloc(sizeof(char) * (len + 1));
	if (!copy_malloc)
		return (NULL);
	return (copy_malloc);
}

static size_t	full_length(unsigned int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len++;
	while (n > 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_utoa(unsigned int n)
{
	char	*copy;
	size_t	len;

	len = full_length(n);
	copy = make_malloc(len);
	if (!copy)
		return (NULL);
	copy[len] = '\0';
	if (n == 0)
		copy[0] = '0';
	else
	{
		while (n > 0)
		{
			copy[--len] = (n % 10) + '0';
			n = n / 10;
		}
	}
	return (copy);
}
