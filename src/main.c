/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomez-f <tgomez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 18:22:51 by tgomez-f          #+#    #+#             */
/*   Updated: 2026/01/30 16:45:39 by tgomez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
 
#include <stdio.h>

void	debug_data(t_data *data);


int	main(int ac, char **av)
{
	t_data  data;
	t_map   map;
    t_mlx   mlx;
	
	init_all(&data, &map, &mlx);
	parsing(ac, av[1], &data);
    //debug_data(&data);
	//mlx_loop_hook(data.mlx->mlx, render, &data);
    events_hooks(&data);
	mlx_loop(mlx.mlx);
}






































void	debug_data(t_data *data)
{
	int	i;

	printf("===== DEBUG DATA =====\n");

	/* Window / MLX */
	printf("MLX ptr      : %p\n", data->mlx);
	printf("Window ptr   : %p\n", data->mlx->window);
	/* Textures */
	printf("---- TEXTURES ----\n");
	printf("NO: path=%s | loaded=%d\n",
		data->map->NO_texture.path ? data->map->NO_texture.path : "(null)",
		data->map->NO_texture.loaded);

	printf("SO: path=%s | loaded=%d\n",
		data->map->SO_texture.path ? data->map->SO_texture.path : "(null)",
		data->map->SO_texture.loaded);

	printf("EA: path=%s | loaded=%d\n",
		data->map->EA_texture.path ? data->map->EA_texture.path : "(null)",
		data->map->EA_texture.loaded);

	printf("WE: path=%s | loaded=%d\n\n",
		data->map->WE_texture.path ? data->map->WE_texture.path : "(null)",
		data->map->WE_texture.loaded);

	/* Colors */
	printf("---- COLORS ----\n");
	printf("Ceiling: R=%d G=%d B=%d | loaded=%d\n",
		data->map->ceiling_color.r,
		data->map->ceiling_color.g,
		data->map->ceiling_color.b,
		data->map->ceiling_color.loaded);

	printf("Floor  : R=%d G=%d B=%d | loaded=%d\n\n",
		data->map->floor_color.r,
		data->map->floor_color.g,
		data->map->floor_color.b,
		data->map->floor_color.loaded);

	/* Map info */
	printf("---- MAP INFO ----\n");
	printf("Map width  : %d\n", data->map->map_width);
	printf("Map height : %d\n", data->map->map_height);
	printf("Spawn X    : %d\n", data->map->spawn_x);
	printf("Spawn Y    : %d\n", data->map->spawn_y);
	printf("Spawn dir  : %c\n\n", data->map->spawn_direction);

	/* Map grid */
	printf("---- MAP GRID ----\n");
	if (!data->map->map_grid)
		printf("(map_grid is NULL)\n");
	else
	{
		i = 0;
		while (data->map->map_grid[i])
		{
			printf("[%02d] %s\n", i, data->map->map_grid[i]);
			i++;
		}
	}

	/* File grid */
	printf("\n---- FILE GRID ----\n");
	if (!data->file_grid)
		printf("(file_grid is NULL)\n");
	else
	{
		i = 0;
		while (data->file_grid[i])
		{
			printf("[%02d] %s\n", i, data->file_grid[i]);
			i++;
		}
	}

	printf("===== END DEBUG =====\n");
}