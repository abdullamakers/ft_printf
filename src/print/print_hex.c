/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdualsh <abdualsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:30:20 by abdualsh          #+#    #+#             */
/*   Updated: 2025/11/14 16:51:01 by abdualsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned int n, char format)
{
	char	*hex;
	int		len;

	hex = ft_itox((unsigned long long)n, format);
	if (!hex)
		return (-1);
	ft_putstr(hex);
	len = ft_strlen(hex);
	free(hex);
	return (len);
}
