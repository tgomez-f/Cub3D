/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_closed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomez-f <tgomez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:20:32 by tgomez-f          #+#    #+#             */
/*   Updated: 2026/02/03 15:48:30 by tgomez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	check_cell(char c, t_data *data, int x, int y)
{
	if (c != '1' && c != '0')
	{
		printf("x: %d\ny: %d\n", x, y);
		printf(NBLUE"%c\n"RST, c);
		exit_error("Parsing: (Map is not closed)", data);
	}
}

void	surrounded_walls(char **grid, int y, int x, t_data *data)
{
	check_cell(grid[y - 1][x], data, x, y);
	check_cell(grid[y + 1][x], data, x, y);
	check_cell(grid[y][x - 1], data, x, y);
	check_cell(grid[y][x + 1], data, x, y);
}

void	check_map_closed(t_data *data, char **grid, int y)
{
	int	x;

	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == '0')
				surrounded_walls(grid, y, x, data);
			x++;
		}
		y++;
	}
}
