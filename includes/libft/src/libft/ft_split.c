/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomez-f <tgomez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:33:35 by tgomez-f          #+#    #+#             */
/*   Updated: 2025/05/25 17:48:03 by tgomez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	variable(size_t *i, int *start, int *j)
{
	*i = 0;
	*j = 0;
	*start = -1;
}

static int	word_count(const char *s, char c)
{
	int	i;
	int	count_w;
	int	flag;

	flag = 0;
	i = 0;
	count_w = 0;
	while (s[i])
	{
		if (s[i] != c && flag == 0)
		{
			flag = 1;
			count_w++;
		}
		else if (s[i] == c)
			flag = 0;
		i++;
	}
	return (count_w);
}

static void	*ft_free(char **array, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

static char	*fill_word(const char *str, int start, int end)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_split(const char *s, char c)
{
	int		start;
	int		j;
	size_t	i;
	char	**array;

	variable(&i, &start, &j);
	array = ft_calloc(sizeof(char *), (word_count(s, c) + 1));
	if (!array)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			array[j] = fill_word(s, start, i);
			if (!(array[j]))
				return (ft_free(array, j));
			start = -1;
			j++;
		}
		i++;
	}
	return (array);
}
// int	main(void)
//{
//	int i = 0;
//	char *test = "je suis Thomas";
//	char **splited = ft_split(test, '');
//	while (splited[i])
//	{
//		printf("test : %s\n", splited[i]);
//		i++;
//	}
//	return(0);
//}