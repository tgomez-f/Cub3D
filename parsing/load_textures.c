/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomez-f <tgomez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 13:19:13 by tgomez-f          #+#    #+#             */
/*   Updated: 2026/02/02 15:40:45 by tgomez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	load_textures(t_texture *texture, t_data *data, char *path)
{
	int width;
	int height;

	texture->img = mlx_xpm_file_to_image(data->mlx->mlx, path, &width, &height);
	if (!texture->img)
		exit_error("Parsing: (Failed to load texture)");
}

void	check_loaded(t_texture *texture, char *path, t_data *data)
{
	if (texture->loaded)
		exit_error("Parsing: (Texture defined more than once)");
	else
	{
		texture->loaded = true;
		texture->path = path;
		(void)data;
		//load_textures(texture, data, path);
	}
}
