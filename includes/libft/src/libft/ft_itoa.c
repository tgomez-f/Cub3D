/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomez-f <tgomez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:32:02 by tgomez-f          #+#    #+#             */
/*   Updated: 2025/05/23 17:19:41 by tgomez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_nb(int nb)
{
	int	c;

	c = 0;
	if (nb < 0)
	{
		c++;
		nb = -nb;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		c++;
	}
	return (c);
}

static char	*edge_case(int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	return (NULL);
}

char	*ft_itoa(int n)
{
	const int	len = count_nb(n);
	int			i;
	char		*str;

	if (n == 0 || n == INT_MIN)
		return (edge_case(n));
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	i = len - 1;
	while (n > 0)
	{
		str[i] = ((n % 10) + 48);
		n = n / 10;
		i--;
	}
	str[len] = 0;
	return (str);
}
/*
int	main(void)
{

	printf("%s\n", ft_itoa(1234));

	printf("%s\n", ft_itoa(-1234));

	printf("%s\n", ft_itoa(0));

	return(0);
}*/