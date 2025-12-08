/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdualsh <abdualsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:30:06 by abdualsh          #+#    #+#             */
/*   Updated: 2025/12/08 13:33:30 by abdualsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

static int data_processing(va_list *args,int total,char copy)
{
	if((copy == 'c'))
		total = total + process_c(va_arg(*args,int));
	else if((copy == 's'))
		total = total + process_s(va_arg(*args,char *));
	else if((copy == 'p'))
		total = total + process_p(va_arg(*args,void *));
	else if((copy == 'd') || (copy == 'i'))
		total = total + process_d_i(va_arg(*args,int),copy);
	else if((copy == 'u'))
		total = total + process_u(va_arg(*args,unsigned int));	
	else if((copy == 'x') || (copy == 'X'))
		total = total + process_x_X(va_arg(*args,unsigned int),copy);
	else if((copy == '%'))
		total = total + print_char('%');
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
			if(*(format + 1))
			{
			total = data_processing(&args,total,*(format + 1));
			format = format + 2;
			}
			else
				format++;
		}
		else
		{
			total = total + print_char(*format);
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
