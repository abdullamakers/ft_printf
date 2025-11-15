/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdualsh <abdualsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:30:30 by abdualsh          #+#    #+#             */
/*   Updated: 2025/11/14 16:54:29 by abdualsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unbr(unsigned int n)
{
	char	*unbr;
	int		len;

	unbr = ft_utoa(n);
	if (!unbr)
		return (-1);
	ft_putstr(unbr);
	len = ft_strlen(unbr);
	free(unbr);
	return (len);
}
