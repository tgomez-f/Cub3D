/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomez-f <tgomez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 13:19:13 by tgomez-f          #+#    #+#             */
/*   Updated: 2026/02/03 15:18:51 by tgomez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	load_textures(t_texture *texture, t_data *data, char *path)
{
	int width;
	int height;

	texture->img = mlx_xpm_file_to_image(data->mlx->mlx, path, &width, &height);
	if (!texture->img)
		exit_error("Parsing: (Failed to load texture)", data);
}

void	check_loaded(t_texture *texture, char *path, t_data *data)
{
	if (texture->loaded)
		exit_error("Parsing: (Texture defined more than once)", data);
	else
	{
		texture->loaded = true;
		texture->path = path;
		(void)data;
		//load_textures(texture, data, path);
	}
}

static char	*trim_end(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (i >= 0 && (str[i] == '\n' || str[i] == ' ' || str[i] == '\t'))
	{
		str[i] = '\0';
		i--;
	}
	return (str);
}

void	xpm_extention(char *filename, t_data *data)
{
	int	map_name_len;

	trim_end(filename);
	map_name_len = ft_strlen(filename);
	if (!ft_strnstr(&filename[map_name_len - 4], ".xpm", 4))
		exit_error("Parsing: (Texture extention is wrong, Need *.xpm)\n", data);
}

void	save_textures(t_data *data, int orientation, char *path)
{
	t_texture	*textures[4] = {&data->map->NO_texture, &data->map->SO_texture,
			&data->map->EA_texture, &data->map->WE_texture};
	xpm_extention(path, data);
	check_loaded(textures[orientation], path, data);
}
