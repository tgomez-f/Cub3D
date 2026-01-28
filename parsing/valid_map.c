/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomez-f <tgomez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:32:42 by tgomez-f          #+#    #+#             */
/*   Updated: 2026/01/28 15:02:29 by tgomez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	valid_map(t_data *data)
{
	int	y;
	
	y = 0;
	while (data->file_grid[y] && !check_map_line(data->file_grid[y]))
		y++;
	printf("\n%d\n", y);
	
}