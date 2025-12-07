/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdualsh <abdualsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:30:06 by abdualsh          #+#    #+#             */
/*   Updated: 2025/12/07 15:20:06 by abdualsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

static int data_processing(va_list args,int total,char copy)
{
	int test;

	test = 0;
	if((copy == 'c'))
		total = total + file_data_process(copy,va_arg(args,int));
	else if((copy == ''))
		total = total + (copy,va_arg(args,type));	

	//!else()
	//! this is doing a next time, because i need time to fixed
	return(total);
}

static int core(va_list args, const char *format)
{
	int	total;
	
	total = 0;
	while(*format)
	{
		if(*format == '%')
		{
			total = data_processing(args,total,*(format + 1));
			format++;
		}
		else
		{
			total = totalprint_char(*(format));
			format++;
		}
	}
	return(total);
}

int ft_printf(const char *format, ...)
{
	va_list		args;
	int			total_length_doin;
	
	va_start (args, format);
	total_length_doin = core(args,format);
	va_end (args);
	return (total_length_doin);
}
