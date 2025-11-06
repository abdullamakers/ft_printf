/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdualsh <abdualsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:30:09 by abdualsh          #+#    #+#             */
/*   Updated: 2025/11/01 18:02:29 by abdualsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_flags
{
	int minus;//$ left-aligns the output inside the field(%-d)
	int zero;//$ pads the number with zeros instead of spaces (%05d)
	int width;//$ sets the minimum width of the printed field (%8d)
	int dot;//$ activates precision control (%.3d)
	int precision;//$ limits number of digits or characters (%.3d, %.5s)
	int hash;//$ adds a prefix like 0x or 0X for hex (%#x)
	int space;//$ adds a space before positive numbers (%d)
	int plus;//$ adds a + sign before positive numbers (%+d)
    
} t_flags;

//#-------- Mandatory ----------

int	ft_printf(const char *format, ...);		//! The main function — reads the format string and prints all arguments.
int	print_char(char c);						//! Prints one character (%c).
int	print_str(char *s);						//! Prints a string (%s).
int	print_ptr(unsigned long long ptr);		//! Prints a pointer address in hexadecimal with 0x (%p).
int	print_nbr(int n);						//! Prints a signed integer (%d or %i).
int	print_unbr(unsigned int n);				//! Prints an unsigned integer (%u).
int	print_hex(unsigned int n, char format);	//! Prints a number in hexadecimal (%x for lowercase, %X for uppercase).

//# -------- Utils ----------
size_t	ft_strlen(const char *s);	//! Returns the length of a string.
void	ft_putchar(char c);			//! Prints one character (used internally).
void	ft_putstr(char *s);			//! Prints a string (used internally).
char	*ft_itoa(int n);			//! Converts an integer to a string.
char	*ft_utoa(unsigned int n);	//! Converts an unsigned int to a string.
char	*ft_itox(unsigned long long n, char format);	//! Converts a number to a hexadecimal string.

//# -------- Bonus ----------
int	parse_flags(const char *fmt, int i, t_flags *flags, va_list args);	//! Reads and stores all format flags (-, 0, ., width, etc.).
int	handle_flags(t_flags flags, char specifier, va_list args);	//! Applies the flags (alignment, padding, signs) before printing.
int	print_bonus_utils(char *str, t_flags flags);				//! Helper functions for applying flags to output text.
int pad_left(char *str, t_flags flags);							//! Adds spaces or zeros on the left.
int pad_right(char *str, t_flags flags);						//! Adds spaces on the right.
int add_prefix(char *str, t_flags flags, char spec);			//! Adds prefixes like 0x, +, or space if needed.

#endif