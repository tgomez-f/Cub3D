/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomez-f <tgomez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 09:59:24 by tgomez-f          #+#    #+#             */
/*   Updated: 2026/01/27 12:37:45 by tgomez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*read_loop(char *stash, int fd, char *buff)
{
	char	*tmp;
	int		nbytes;

	nbytes = 1;
	while (!ft_strchr(stash, '\n') && nbytes > 0)
	{
		nbytes = read(fd, buff, BUFFER_SIZE);
		if (nbytes < 0)
			return (free(buff), NULL);
		buff[nbytes] = '\0';
		tmp = ft_strjoin(stash, buff);
		free(stash);
		if (!tmp)
			return (NULL);
		stash = tmp;
	}
	return (stash);
}

static char	*reading(char *stash, int fd)
{
	char	*buff;

	if (!stash)
	{
		stash = ft_strdup("");
		if (!stash)
			return (NULL);
	}
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (free(stash), NULL);
	stash = read_loop(stash, fd, buff);
	free(buff);
	if (!stash)
	{
		free(stash);
		return (NULL);
	}
	return (stash);
}

static char	*take_line(char *stash)
{
	int	i;

	i = 0;
	if (!stash || stash[0] == '\0')
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	return (ft_substr(stash, 0, i));
}

static char	*clean_stash(char *stash)
{
	int		i;
	char	*new_stash;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_strdup(stash + i + 1);
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	stash = reading(stash, fd);
	if (!stash)
		return (NULL);
	line = take_line(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = clean_stash(stash);
	return (line);
}
