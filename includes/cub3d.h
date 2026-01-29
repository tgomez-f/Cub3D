/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomez-f <tgomez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 18:23:36 by tgomez-f          #+#    #+#             */
/*   Updated: 2026/01/29 13:40:22 by tgomez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "X11/keysym.h"
# include "color.h"
# include "libft/includes/libft.h"
# include "mlx.h"
# include "struct.h"
# include <stdbool.h>


void	init_all(t_data *data, t_map *map, t_mlx *mlx);

void	init_mlx(t_data *data, t_mlx *mlx);

//================================   PARSING ======

void	parsing(int ac, char *av1, t_data *data);

void	alloc_file(int file_height, t_data *data, char *file);

void	valid_file(t_data *data);

void	valid_assets(t_data *data);

void	handle_colors(t_data *data, char *values, char id_color);

void	valid_map(t_data *data);

void	check_map_closed(char **grid, int y);

//=============================== GRAPHICS ========


void	events_hooks(t_data *data);

//===============================  UTILS ==========

void	exit_error(char *str);

char	*rm_spaces(char *line);

int	is_map_line(char *line);

int	line_empty(char *str);


#endif