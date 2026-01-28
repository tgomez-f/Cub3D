/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomez-f <tgomez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 11:33:47 by tgomez-f          #+#    #+#             */
/*   Updated: 2026/01/27 17:47:15 by tgomez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	line_empty(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (!ft_isspace((unsigned char)str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	fill_file_grid(t_data *data, char *file)
{
	char	*line;
	int		i;
	int		fd;
	
	i = 0;
	fd = open(file, O_RDONLY | 0644);
	if (fd < 0)
		exit_error("Can't open file");
	line = get_next_line(fd);
	while (line)
	{
		if (line_empty(line))
		{
			line = get_next_line(fd);
			continue;
		}
		data->file_grid[i] = line;
		//printf("%s", data->file_grid[i]);
		line = get_next_line(fd);
		i++;
	}
	data->file_grid[i] = NULL;
	close(fd);
}

void	alloc_file(int file_height, t_data *data, char *file)
{
	data->file_grid = malloc(sizeof(char *) * (file_height + 1));
	if (!data->file_grid)
		exit_error("Allocation of file failed");
	fill_file_grid(data, file);
}
