/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomez-f <tgomez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:34:45 by tgomez-f          #+#    #+#             */
/*   Updated: 2026/02/03 14:52:34 by tgomez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	get_map_height(char **grid, int y)
{
	int	h;

	h = 0;
	while (grid[y + h] && is_map_line(grid[y + h]))
		h++;
	return (h);
}

static int	get_map_width(char **grid, int y, int height)
{
	int	i;
	int	max;
	int	len;

	i = 0;
	max = 0;
	while (i < height)
	{
		len = ft_strlen(grid[y + i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}

void	fill_map_grid(t_data *data, int y)
{
	int	i;
	int	j;

	data->map->map_height = get_map_height(data->file_grid, y);
	data->map->map_width = get_map_width(
		data->file_grid, y, data->map->map_height);

	data->map->map_grid = malloc(sizeof(char *)
			* (data->map->map_height + 1));
	if (!data->map->map_grid)
		exit_error("Alloc: Malloc failed (map_grid)", data);

	i = 0;
	while (i < data->map->map_height)
	{
		data->map->map_grid[i] = malloc(sizeof(char)
				* (data->map->map_width + 1));
		if (!data->map->map_grid[i])
			exit_error("Alloc: Malloc failed (map_grid line)", data);

		j = 0;
		while (j < data->map->map_width)
		{
			if (j < (int)ft_strlen(data->file_grid[y + i]))
				data->map->map_grid[i][j] = data->file_grid[y + i][j];
			else
				data->map->map_grid[i][j] = ' '; // padding
			j++;
		}
		data->map->map_grid[i][j] = '\0';
		i++;
	}
	data->map->map_grid[i] = NULL;
}
