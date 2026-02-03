/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomez-f <tgomez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 20:22:46 by tgomez-f          #+#    #+#             */
/*   Updated: 2026/02/03 15:07:01 by tgomez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	take_color(char *values, int *i, t_data *data)
{
	int	new_value;

	while (values[*i] && ft_isspace(values[*i]))
	(*i)++;
	if (values[*i] && !ft_isdigit(values[*i]))
		exit_error("RGB values wrong (value is not digits)", data);
	new_value = 0;
	while (ft_isdigit(values[*i]))
	{
		new_value = new_value * 10 + (values[*i] - '0');
		(*i)++;
	}
	if (new_value > 255)
		exit_error("RGB values wrong (value is above 255)", data);
	return (new_value);
}

static	void check_loaded_color(t_color *color, t_data *data)
{
	if (color->loaded == true)
		exit_error("Parsing: (Color defined more than once)", data);
	else
		color->loaded = true;
}

void	handle_colors(t_data *data, char *values, char id_color)
{
	int		i;
	t_color	*color;

	color = NULL;
	i = 1;
	if (id_color == 'C')
		color = &data->map->ceiling_color;
	else if (id_color == 'F')
		color = &data->map->floor_color;
	else
		exit_error("Parsing: (Unknown color identifier)", data);
	check_loaded_color(color, data);
	color->r = take_color(values, &i, data);
	if (values[i++] != ',')
		exit_error("RGB values wrong (missing comma 1)", data);
	color->g = take_color(values, &i, data);
	if (values[i++] != ',')
		exit_error("RGB values wrong (missing comma 2)", data);
	color->b = take_color(values, &i, data);
	if (!values[i])
		exit_error("RGB values wrong (missing input)", data);
	while (values[i] && ft_isspace(values[i]))
		i++;
	if (values[i])
		exit_error("RGB values wrong (extra characters)", data);
}
