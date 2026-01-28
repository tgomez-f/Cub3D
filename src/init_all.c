/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomez-f <tgomez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 18:41:17 by tgomez-f          #+#    #+#             */
/*   Updated: 2026/01/28 17:05:05 by tgomez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"


void	init_all(t_data *data)
{
	ft_bzero(data->map, sizeof(t_map));

	//data->map->NO_texture.loaded = false;
    //data->map->SO_texture.loaded = false;
    //data->map->EA_texture.loaded = false;
    //data->map->WE_texture.loaded = false;
}
