/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomez-f <tgomez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:32:23 by tgomez-f          #+#    #+#             */
/*   Updated: 2025/05/23 16:14:47 by tgomez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*temp;

	temp = (unsigned char *)s;
	while (len > 0)
	{
		*temp = (unsigned char)c;
		temp++;
		len--;
	}
	return (s);
}
/*
int	main(void)
{
	char str[50] = "GeeksForGeeks is for programming geeks.";
	printf("\nBefore memset(): %s\n", str);

	memset(str + 13, '.', 8 * sizeof(char));
	printf("After memset():  %s\n", str);

	ft_memset(str + 13, '.', 8 * sizeof(char));
	printf("After ft_memset(): %s\n", str);

	return (0);
}*/