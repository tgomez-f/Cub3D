/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomez-f <tgomez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:25:54 by tgomez-f          #+#    #+#             */
/*   Updated: 2025/09/10 13:38:42 by tgomez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printarg(const char n, va_list args)
{
	int		count;
	char	*lower_hex;
	char	*upper_hex;

	lower_hex = "0123456789abcdef";
	upper_hex = "0123456789ABCDEF";
	count = 0;
	if (n == 'c')
		count += ft_printf_putchar_fd(va_arg(args, int), 1);
	else if (n == 's')
		count += ft_printf_putstr_fd(va_arg(args, char *), 1);
	else if (n == 'p')
		count += ft_putnbr_base((unsigned long)va_arg(args, void *), lower_hex,
				16, 'p');
	else if (n == 'd' || n == 'i')
		count += ft_printf_putnbr_fd(va_arg(args, int), 1);
	else if (n == 'u')
		count += ft_putunbr_fd(va_arg(args, unsigned int), 1);
	else if (n == 'x')
		count += ft_putnbr_base(va_arg(args, unsigned int), lower_hex, 16, n);
	else if (n == 'X')
		count += ft_putnbr_base(va_arg(args, unsigned int), upper_hex, 16, n);
	else if (n == '%')
		count += ft_printf_putchar_fd('%', 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
				return (count);
			count += printarg(*format, args);
		}
		else
			count += ft_printf_putchar_fd(*format, 1);
		++format;
	}
	va_end(args);
	return (count);
}
