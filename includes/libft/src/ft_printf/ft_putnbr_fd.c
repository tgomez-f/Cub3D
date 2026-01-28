/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomez-f <tgomez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:33:24 by tgomez-f          #+#    #+#             */
/*   Updated: 2025/09/10 13:35:04 by tgomez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_putnbr_fd(int n, int fd)
{
	int	count;

	count = 0;
	if (n == 0)
		return (ft_printf_putchar_fd('0', fd));
	if (n == INT_MIN)
	{
		count += ft_printf_putstr_fd("-2147483648", fd);
		return (count);
	}
	if (n < 0)
	{
		count += ft_printf_putchar_fd('-', fd);
		n = -n;
	}
	if (n > 9)
	{
		count += ft_printf_putnbr_fd(n / 10, fd);
		count += ft_printf_putnbr_fd(n % 10, fd);
	}
	else
		count += ft_printf_putchar_fd(n + '0', fd);
	return (count);
}
