/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomez-f <tgomez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:32:42 by tgomez-f          #+#    #+#             */
/*   Updated: 2026/01/29 14:05:16 by tgomez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	check_spawn_pos(t_data *data, char **grid, int y)
{
	int	x;
	int	count_spawn;

	count_spawn = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x++])
		{
			if (grid[y][x] == 'N' || grid[y][x] == 'S' || grid[y][x] == 'E'
				|| grid[y][x] == 'W')
			{
				data->map->spawn_x = x;
				data->map->spawn_y = y;
				data->map->spawn_direction = grid[y][x];
				data->file_grid[y][x] = '0';
				count_spawn++;
			}
		}
		y++;
	}
	if (count_spawn != 1)
		exit_error("0 or more than 1 spawn");
}

void	check_invalid_char(char **grid, int y)
{
	int	x;

	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (!grid[y][x] && grid[y][x] != 'N' && grid[y][x] != 'S'
				&& grid[y][x] != 'E' && grid[y][x] != 'W' && grid[y][x] != '1'
				&& grid[y][x] != '0' && grid[y][x] != ' ')
			{
				printf("\n\n\n'%c'", grid[y][x]);
				exit_error("Invalid char in the map");
			}
			x++;
		}
		y++;
	}
}

int	find_start_map(char **grid)
{
	int	y;

	y = 0;
	while (grid[y])
	{
		if (is_map_line(grid[y]))
			return (y);
		y++;
	}
	exit_error("There is no map ?");
	return (-1);
}

void	valid_map(t_data *data)
{
	int	y;

	y = find_start_map(data->file_grid);
	check_spawn_pos(data, data->file_grid, y);
	check_invalid_char(data->file_grid, y);
	check_map_closed(data->file_grid, y);
}
