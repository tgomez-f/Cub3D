/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_closed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomez-f <tgomez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:20:32 by tgomez-f          #+#    #+#             */
/*   Updated: 2026/01/29 12:19:54 by tgomez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	check_cell(char c)
{
	if (c != '1' && c != '0')
		exit_error("Map is not closed");
}

void	surrounded_walls(char **grid, int y, int x)
{
	check_cell(grid[y - 1][x]);
	check_cell(grid[y + 1][x]);
	check_cell(grid[y][x - 1]);
	check_cell(grid[y][x + 1]);
}

void	check_map_closed(char **grid, int y)
{
	int	x;

	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == '0')
				surrounded_walls(grid, y, x);
			x++;
		}
		y++;
	}
}
