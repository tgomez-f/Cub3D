/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomez-f <tgomez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:55:56 by tgomez-f          #+#    #+#             */
/*   Updated: 2025/09/10 13:34:32 by tgomez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_base(unsigned long long num, char *base, int base_len)
{
	char	str[32];
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (num == 0)
		return (ft_printf_putchar_fd(base[0], 1));
	while (num != 0)
	{
		str[i++] = base[num % base_len];
		num /= base_len;
	}
	while (i--)
		count += ft_printf_putchar_fd(str[i], 1);
	return (count);
}

int	ft_putnbr_base(unsigned long long nbr, char *base, int base_len, char n)
{
	int	count;

	count = 0;
	if (n == 'p' && !nbr)
		return (ft_printf_putstr_fd("(nil)", 1));
	else if (n == 'p')
		count += ft_printf_putstr_fd("0x", 1);
	count += print_base(nbr, base, base_len);
	return (count);
}
