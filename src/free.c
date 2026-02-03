/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomez-f <tgomez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:49:23 by tgomez-f          #+#    #+#             */
/*   Updated: 2026/02/03 15:36:22 by tgomez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	free_str_tab(char **tab)
{
	int	i;

	if (!tab)
		return;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static void	free_texture(t_mlx *mlx, t_texture *tex)
{
	if (!tex)
		return;
	if (tex->loaded && tex->img && mlx && mlx->mlx)
		mlx_destroy_image(mlx->mlx, tex->img);
	tex->img = NULL;
	tex->path = NULL;
	tex->loaded = false;
}

static void	free_map(t_data *data)
{
	if (!data->map)
		return;

	free_texture(data->mlx, &data->map->NO_texture);
	free_texture(data->mlx, &data->map->SO_texture);
	free_texture(data->mlx, &data->map->EA_texture);
	free_texture(data->mlx, &data->map->WE_texture);
	if (data->map->map_grid)
		free_str_tab(data->map->map_grid);
}

static void	free_mlx(t_mlx *mlx)
{
	if (!mlx)
		return;
	if (mlx->img && mlx->mlx)
		mlx_destroy_image(mlx->mlx, mlx->img);
	if (mlx->window && mlx->mlx)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx->mlx)
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
}

void	ft_free_all(t_data *data)
{
	if (!data)
		return;
	if (data->file_grid)
		free_str_tab(data->file_grid);
	free_map(data);
	if (data->mlx)
		free_mlx(data->mlx);
}
