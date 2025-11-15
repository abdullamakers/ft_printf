/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdualsh <abdualsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:30:24 by abdualsh          #+#    #+#             */
/*   Updated: 2025/11/14 16:54:12 by abdualsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(unsigned long long ptr)
{
	char	*add_ress;
	int		len;

	if (ptr == 0)
	{
		ft_putstr("0x0");
		return (3);
	}
	add_ress = ft_itox(ptr, 'x');
	if (!add_ress)
		return (-1);
	len = ft_strlen(add_ress) + 2;
	ft_putstr("0x");
	ft_putstr(add_ress);
	free(add_ress);
	return (len);
}
