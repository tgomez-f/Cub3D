/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomez-f <tgomez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:32:21 by tgomez-f          #+#    #+#             */
/*   Updated: 2025/05/23 16:55:18 by tgomez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dest_temp;
	char	*src_temp;

	i = 0;
	dest_temp = dest;
	src_temp = (char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest_temp > src_temp)
	{
		i = n;
		while (i > 0)
		{
			i--;
			dest_temp[i] = src_temp[i];
		}
		return (dest);
	}
	while (i < n)
	{
		dest_temp[i] = src_temp[i];
		i++;
	}
	return (dest);
}
