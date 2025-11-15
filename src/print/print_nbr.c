/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdualsh <abdualsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:30:23 by abdualsh          #+#    #+#             */
/*   Updated: 2025/11/14 16:54:08 by abdualsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr(int n)
{
	char	*s;
	int		len;

	s = ft_itoa(n);
	if (!s)
	{
		return (-1);
	}
	ft_putstr(s);
	len = ft_strlen(s);
	free(s);
	return (len);
}
