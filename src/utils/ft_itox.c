/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdualsh <abdualsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 00:33:07 by abdualsh          #+#    #+#             */
/*   Updated: 2025/11/02 15:12:19 by abdualsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void copy_data(char *hex, unsigned long long n, int len)
{
	int size;
	
	hex[len] = '\0';
	len--;
	
	while (len >= 0)
	{
		size = n % 16;
		if(size <= 9 && size >= 0)
			hex[len] = size + '0' ;
		else
		{
			size = size - 10;
			hex[len] = size + 'a';
		}
		n = n / 16;
		len--;
	}
}

static char *add_malloc(size_t len)
{
	char *hex;
	
	hex = malloc(sizeof(char) * (len + 1));
	if(!hex)
		return(NULL);
	return(hex);
}

char *ft_itox(unsigned long long n, char format)
{
	char *hex;
	unsigned long long nn;
	size_t len;
	
	len = 0;
	nn = n;
	if (nn == 0)
		len++;
	while(nn > 0)
	{
		nn = nn / 16;
		len++;
	}
	hex = add_malloc(len);
	copy_data(hex,n ,(int)len)
}
