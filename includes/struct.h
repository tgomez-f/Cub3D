/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomez-f <tgomez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 18:26:49 by tgomez-f          #+#    #+#             */
/*   Updated: 2026/01/30 14:45:59 by tgomez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdbool.h>

# define TILE 32

# define HEIGHT 800
# define WIDTH 800

enum			e_orientation
{
	NORTH,
	SOUTH,
	EAST,
	WEST,

};

typedef struct s_texture
{
	void		*img;
	char		*path;

	bool		loaded;
}				t_texture;

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
	bool		loaded;
}				t_color;

typedef struct s_map
{
	char		**map_grid;

	int			map_width;
	int			map_height;
	
	t_texture	NO_texture;
	t_texture	SO_texture;
	t_texture	EA_texture;
	t_texture	WE_texture;

	t_color		ceiling_color;
	t_color		floor_color;

	int			spawn_x;
	int			spawn_y;
	char		spawn_direction;
}				t_map;

typedef struct s_vector
{
	double		x;
	double		y;
}				t_vector;

typedef struct s_player
{
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
}				t_player;

typedef struct s_mlx
{
	void		*mlx;
	void		*window;
	void		*img;
	char		*buffer;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			buffer_size;
}				t_mlx;

typedef struct s_data
{
	t_mlx		*mlx;
	t_map		*map;
	t_player	player;

	char		**file_grid;
}				t_data;

#endif