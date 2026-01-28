/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomez-f <tgomez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 09:57:44 by tgomez-f          #+#    #+#             */
/*   Updated: 2025/09/10 13:36:03 by tgomez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr_fd(unsigned int n, int fd)
{
	int	count;

	count = 0;
	if (n == 0)
		return (ft_printf_putchar_fd('0', fd));
	if (n > 9)
	{
		count += ft_putunbr_fd(n / 10, fd);
		count += ft_putunbr_fd(n % 10, fd);
	}
	else
		count += ft_printf_putchar_fd(n + '0', fd);
	return (count);
}
