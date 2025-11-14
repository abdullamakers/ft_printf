/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: server-2 <server-2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 00:33:07 by abdualsh          #+#    #+#             */
/*   Updated: 2025/11/11 16:22:31 by server-2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	str_size(unsigned long long n)
{
	size_t	len_n;

	len_n = 0;
	while (((n % 16) != 0) && (n != 16))
	{
		n = n / 16;
		len_n++;
	}
	if (n == 16)
		len_n = len_n + 2;
	return (len_n);
}

static void	copy_data(char *hex, unsigned long long n, size_t len_n)
{
	hex[len_n] = '\0';
	len_n--;
	while (((n % 16) != 0) && (n != 16))
	{
		if (n % 16 <= 9)
		{
			hex[len_n] = (n % 16) + '0';
		}
		else
		{
			hex[len_n] = 'a' + ((n % 16) - 10);
		}
		len_n--;
		n = n / 16;
	}
	if (n == 16)
	{
		hex[len_n] = '0';
		hex[len_n - 1] = '1';
	}
}

static char	*add_malloc(size_t len_n)
{
	char	*copy;

	copy = malloc(sizeof(char) * (len_n + 1));
	if (!copy)
		return (NULL);
	return (copy);
}

static void	change_capital(char *str)
{
	int	x;

	x = 0;
	while (str[x])
	{
		if (str[x] >= 'a' && str[x] <= 'f')
			str[x] = str[x] - 32;
		x++;
	}
}

char	*ft_itox(unsigned long long n, char format)
{
	char	*copy;
	size_t	len_n;

	len_n = str_size(n);
	copy = add_malloc(len_n);
	copy_data(copy, n, len_n);
	if (format >= 'X')
		change_capital(copy);
	return (copy);
}
