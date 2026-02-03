/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomez-f <tgomez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:05:44 by tgomez-f          #+#    #+#             */
/*   Updated: 2026/02/03 14:55:08 by tgomez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_win_mouse(t_data *data)
{
	(void)data;
	exit_error("Oh no the window has been destroy.\n", data);
	return (0);
}

int	handle_key(int keycode, t_data *data)
{
	(void)data;
	if (keycode == XK_Escape)
		exit_error("Oh no the window has been destroy.\n", data);
	return (0);
}

void	events_hooks(t_data *data)
{
	mlx_hook(data->mlx->window, 2, 1L << 0, handle_key, data);
	mlx_hook(data->mlx->window, 17, 0, close_win_mouse, data);
}