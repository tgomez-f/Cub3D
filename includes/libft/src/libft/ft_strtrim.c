/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomez-f <tgomez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:34:08 by tgomez-f          #+#    #+#             */
/*   Updated: 2025/05/25 14:36:57 by tgomez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *str, const char *c )
{
	int		end;
	int		start;
	char	*new_str;

	start = 0;
	end = ft_strlen(str);
	while (str[start] && ft_strchr(c, str[start]))
		start++;
	while (end > start && ft_strchr(c, str[end - 1]))
		end--;
	new_str = ft_substr(str, start, end - start);
	return (new_str);
}

//int	main(void)
//{
//	printf("%s\n", ft_strtrim("ababbabaJe deviends foubabababbbb", "ab"));
//	return (0);
//}