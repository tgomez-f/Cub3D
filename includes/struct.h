/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomez-f <tgomez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 18:26:49 by tgomez-f          #+#    #+#             */
/*   Updated: 2026/01/28 16:52:28 by tgomez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdbool.h>
# define WIN_HEIGHT 500
# define WIN_WIDTH 500

enum		e_orientation
{
	NORTH,
	SOUTH,
	EAST,
	WEST,

};

typedef struct s_texture
{
	char	*path;

	bool	loaded;	
} t_texture;


typedef struct s_color
{
	int		r;
	int		g;
	int		b;
	bool	loaded;
}			t_color;

typedef struct s_map
{
	char	**map_grid;

	t_texture	NO_texture;
	t_texture	SO_texture;
	t_texture	EA_texture;
	t_texture	WE_texture;

	t_color	ceiling_color;
	t_color	floor_color;
	
	int		map_width;
	int		map_height;

	int		spawn_x;
	int		spawn_y;
	char	spawn_direction;
}			t_map;

typedef struct s_data
{
	void	*mlx;
	void	*window;

	int		win_width;
	int		win_height;

	char	**file_grid;
	t_map	*map;
}			t_data;

#endif