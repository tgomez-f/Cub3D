/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomez-f <tgomez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:34:48 by tgomez-f          #+#    #+#             */
/*   Updated: 2026/01/28 15:34:15 by tgomez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

//int	refuse_invalid_line(t_data *data)
//{
//	int	y;

//	y = 0;
//	while (data->file_grid[y])
//	{
//		if (strncmp(data->file_grid[y], "NO", 2))
//			return (1);
//		else if (strncmp(data->file_grid[y], "SO", 2))
//			return (1);
//		else if (strncmp(data->file_grid[y], "EA", 2))
//			return (1);
//		else if (strncmp(data->file_grid[y], "WE", 2))
//			return (1);
//		else if (strncmp(data->file_grid[y], "F", 1))
//			return (1);
//		else if (strncmp(data->file_grid[y], "C", 1))
//			return (1);		
//			else if (data->file_grid[y][0] =! 1)
//	}
	
//}

void	valid_file(t_data *data)
{
	//if (refuse_invalid_line(data))
	//	exit_error("Invalid line in the file");
	valid_assets(data);
	valid_map(data);
}