/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomez-f <tgomez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:02:22 by tgomez-f          #+#    #+#             */
/*   Updated: 2025/05/23 15:46:22 by tgomez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	temp_c;
	char	*res;

	temp_c = (char)c;
	i = 0;
	res = NULL;
	while (s[i])
	{
		if (s[i] == temp_c)
			res = (char *)&s[i];
		i++;
	}
	if (s[i] == temp_c)
		res = (char *)&s[i];
	return (res);
}
