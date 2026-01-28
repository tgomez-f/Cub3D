/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomez-f <tgomez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 09:59:30 by tgomez-f          #+#    #+#             */
/*   Updated: 2025/07/02 13:43:27 by tgomez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);

char	*ft_strdup(const char *src);

char	*ft_strjoin(const char *s1, const char *s2);

char	*ft_strchr(const char *s, int c);

char	*ft_substr(const char *s, unsigned int start, size_t len);

#endif