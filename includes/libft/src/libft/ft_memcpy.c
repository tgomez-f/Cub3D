/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomez-f <tgomez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:50:10 by tgomez-f          #+#    #+#             */
/*   Updated: 2025/05/23 15:45:06 by tgomez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*temp_dst;
	unsigned char	*temp_src;

	if (src == 0 && dst == 0)
		return (dst);
	temp_dst = (unsigned char *)dst;
	temp_src = (unsigned char *)src;
	while (n > 0)
	{
		*temp_dst = *temp_src;
		temp_dst++;
		temp_src++;
		n--;
	}
	return (dst);
}
/*
int	main(void)
{
	char str1[] = "";
	char str2[6] = "";

	memcpy(str2, str1, sizeof(str1));

	printf("str2 after memcpy:\n");
	printf("%s\n",str2);

	ft_memcpy(str2, str1, sizeof(str1));
	printf("str2 after ft_memcpy:\n");
	printf("%s\n",str2);

	return (0);
}*/
