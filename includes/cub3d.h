/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomez-f <tgomez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 18:23:36 by tgomez-f          #+#    #+#             */
/*   Updated: 2026/01/28 15:01:07 by tgomez-f         ###   ########.fr       */
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


void	init_all(t_data *data);

//================================   PARSING ======

void	parsing(int ac, char *av1, t_data *data);

void	alloc_file(int file_height, t_data *data, char *file);

void	valid_file(t_data *data);

void	valid_assets(t_data *data);

void	handle_colors(t_data *data, char *values, char id_color);

void	valid_map(t_data *data);

//=============================== GRAPHICS ========

void	start_graphic(t_data *data);

void	events_hooks(t_data *data);

//===============================  UTILS ==========

void	exit_error(char *str);

char	*rm_spaces(char *line);

int	check_map_line(char *line);

#endif