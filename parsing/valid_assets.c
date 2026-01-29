/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_assets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomez-f <tgomez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:57:27 by tgomez-f          #+#    #+#             */
/*   Updated: 2026/01/29 12:12:10 by tgomez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_orientation(char *line)
{
	if (!strncmp(line, "NO", 2))
		return (NORTH);
	else if (!strncmp(line, "SO", 2))
		return (SOUTH);
	else if (!strncmp(line, "EA", 2))
		return (EAST);
	else if (!strncmp(line, "WE", 2))
		return (WEST);
	return (-1);
}

void	check_loaded(t_texture *texture, char *path)
{
	if (texture->loaded)
		exit_error("Texture defined more than once");
	else
	{
		texture->loaded = true;
		texture->path = path;
		// load_textures();
	}
}

void	save_textures(t_data *data, int orientation, char *path)
{
	t_texture	*textures[4] = {&data->map->NO_texture, &data->map->SO_texture,
			&data->map->EA_texture, &data->map->WE_texture};

	check_loaded(textures[orientation], path);
}

static int	check_line_text(char *line, t_data *data)
{
	char	*path;
	char	*after_space;
	int		orientation;

	after_space = rm_spaces(line);
	if (!*after_space)
		return (1);
	orientation = check_orientation(after_space);
	if (orientation == -1)
		return (1);
	path = rm_spaces(after_space + 2);
	if (!*path)
		return (1);
	save_textures(data, orientation, path);
	return (0);
}

static int	check_line_colors(char *line, t_data *data)
{
	char	*after_space;

	after_space = rm_spaces(line);
	if (!*after_space)
		return (1);
	if (*after_space == 'F')
		handle_colors(data, after_space, 'F');
	else if (*after_space == 'C')
		handle_colors(data, after_space, 'C');
	else
		return (1);
	return (0);
}

void	valid_assets(t_data *data)
{
	int		y;
	bool	assets_red;

	assets_red = false;
	y = 0;
	while (data->file_grid[y])
	{
		if (check_line_text(data->file_grid[y], data) == 0
			|| check_line_colors(data->file_grid[y], data) == 0)
		{
			if (assets_red)
				exit_error("Map is above assets");
		}
		else if (is_map_line(data->file_grid[y]))
			assets_red = true;
		else if (line_empty(data->file_grid[y]))
		{
			y++;
			continue;
		}
		else
			exit_error("Invalid line in the file");
		y++;
	}
}
