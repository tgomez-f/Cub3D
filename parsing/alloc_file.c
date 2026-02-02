/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomez-f <tgomez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 11:33:47 by tgomez-f          #+#    #+#             */
/*   Updated: 2026/02/02 15:41:19 by tgomez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	fill_file_grid(t_data *data, char *file)
{
	char	*line;
	int		i;
	int		fd;
	
	i = 0;
	fd = open(file, O_RDONLY | 0644);
	if (fd < 0)
		exit_error("File: (Can't open file)");
	line = get_next_line(fd);
	while (line)
	{
		data->file_grid[i] = line;
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
		exit_error("Alloc: (Allocation of file failed)");
	fill_file_grid(data, file);
}
