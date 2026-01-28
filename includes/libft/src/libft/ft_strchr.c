/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomez-f <tgomez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:34:02 by tgomez-f          #+#    #+#             */
/*   Updated: 2025/05/23 15:46:47 by tgomez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	temp_c;

	temp_c = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == temp_c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == temp_c)
		return ((char *)&s[i]);
	return (NULL);
}
