/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_graphic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomez-f <tgomez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 18:57:41 by tgomez-f          #+#    #+#             */
/*   Updated: 2026/01/16 17:07:49 by tgomez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_graphic(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit_error("Connection to mlx sever fail\n");
	data->win_height = WIN_HEIGHT;
	data->win_width = WIN_WIDTH;
	data->window = mlx_new_window(data->mlx, data->win_width, data->win_height,
			"cub3d askip");
	if (!data->window)
		exit_error("Window creation fail\n");
	events_hooks(data);
	//load_sprites(data);
	//put_sprite_win(data);
}