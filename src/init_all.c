/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomez-f <tgomez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 18:41:17 by tgomez-f          #+#    #+#             */
/*   Updated: 2026/01/29 13:46:53 by tgomez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_mlx(t_data *data, t_mlx *mlx)
{
    ft_bzero(mlx, sizeof(t_mlx));
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		exit_error("Connection to mlx sever fail\n");
	mlx->window = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "cub3d");
	if (!mlx->window)
		exit_error("Window creation fail\n");
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);

	data->mlx = mlx;
}

void	init_all(t_data *data, t_map *map, t_mlx *mlx)
{
    ft_bzero(data, sizeof(t_data));
    data->map = map;
	ft_bzero(data->map, sizeof(t_map));
    init_mlx(data, mlx);
}
