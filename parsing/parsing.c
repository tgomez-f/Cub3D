/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomez-f <tgomez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 18:30:12 by tgomez-f          #+#    #+#             */
/*   Updated: 2026/02/02 15:39:17 by tgomez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	count_lines(char *file)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_error("File: (Can't open file)");
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

void	parse_file(char *map_file, t_data *data)
{
	int	file_height;

	file_height = count_lines(map_file);
	if (file_height <= 0)
		exit_error("File: (The file is empty)");
	alloc_file(file_height, data, map_file);
	valid_file(data);
}


void	extention(char *filename)
{
	int	map_name_len;

	map_name_len = ft_strlen(filename);
	if (!ft_strnstr(&filename[map_name_len - 4], ".cub", 4))
		exit_error("File: (Map file extention is wrong, Need *.cub)\n");
}

void	parsing(int ac, char *av1, t_data *data)
{
	if (ac != 2)
		exit_error("Nombres d'arguments invalides.\n");
	extention(av1);
	parse_file(av1, data);
	
}
