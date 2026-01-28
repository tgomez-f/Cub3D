/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomez-f <tgomez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 18:22:51 by tgomez-f          #+#    #+#             */
/*   Updated: 2026/01/28 16:55:22 by tgomez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
 
int	main(int ac, char **av)
{
	t_data	data;
	t_map	map;

	data.map = &map;	
	init_all(&data);
	parsing(ac, av[1], &data);
if (!data.map)
{
    printf("data.map est NULL !\n");
    return (1);
}

printf("NO texture: loaded=%d, path=%s\n",
    data.map->NO_texture.loaded,
    data.map->NO_texture.path ? data.map->NO_texture.path : "(null)");

printf("SO texture: loaded=%d, path=%s\n",
    data.map->SO_texture.loaded,
    data.map->SO_texture.path ? data.map->SO_texture.path : "(null)");

printf("EA texture: loaded=%d, path=%s\n",
    data.map->EA_texture.loaded,
    data.map->EA_texture.path ? data.map->EA_texture.path : "(null)");

printf("WE texture: loaded=%d, path=%s\n",
    data.map->WE_texture.loaded,
    data.map->WE_texture.path ? data.map->WE_texture.path : "(null)");

printf("Ceiling color: R=%d, G=%d, B=%d\n",
    data.map->ceiling_color.r,
    data.map->ceiling_color.g,
    data.map->ceiling_color.b);

printf("Floor color:   R=%d, G=%d, B=%d\n",
    data.map->floor_color.r,
    data.map->floor_color.g,
    data.map->floor_color.b);

	//start_graphic(&data);
	//mlx_loop(data.mlx);
}
