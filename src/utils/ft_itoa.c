/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdualsh <abdualsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 00:33:05 by abdualsh          #+#    #+#             */
/*   Updated: 2025/11/02 02:40:38 by abdualsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*add_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*dup;

	i = 0;
	len = ft_strlen(s1);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
	{
		return (NULL);
	}
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static unsigned int	ft_len(int n)
{
	unsigned int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int	len;
	char			*ptr;
	int				i;

	if (n == -2147483648)
		return (add_strdup("-2147483648"));
	len = ft_len(n);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ptr[len] = '\0';
	if (n < 0)
	{
		ptr[0] = '-';
		n = -n;
	}
	i = len - 1;
	while (n >= 10)
	{
		ptr[i] = ('0' + (n % 10));
		n = n / 10;
		i--;
	}
	ptr[i] = (n + '0');
	return (ptr);
}
