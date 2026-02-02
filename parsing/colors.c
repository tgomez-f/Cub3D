/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomez-f <tgomez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 20:22:46 by tgomez-f          #+#    #+#             */
/*   Updated: 2026/02/02 15:47:11 by tgomez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	take_color(char *values, int *i)
{
	int	new_value;

	while (values[*i] && ft_isspace(values[*i]))
	(*i)++;
	if (values[*i] && !ft_isdigit(values[*i]))
		exit_error("RGB values wrong (value is not digits)");
	new_value = 0;
	while (ft_isdigit(values[*i]))
	{
		new_value = new_value * 10 + (values[*i] - '0');
		(*i)++;
	}
	if (new_value > 255)
		exit_error("RGB values wrong (value is above 255)");
	return (new_value);
}

static	void check_loaded_color(t_color *color)
{
	if (color->loaded == true)
		exit_error("Parsing: (Color defined more than once)");
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
		exit_error("Parsing: (Unknown color identifier)");
	check_loaded_color(color);
	color->r = take_color(values, &i);
	if (values[i++] != ',')
		exit_error("RGB values wrong (missing comma 1)");
	color->g = take_color(values, &i);
	if (values[i++] != ',')
		exit_error("RGB values wrong (missing comma 2)");
	color->b = take_color(values, &i);
	if (!values[i])
		exit_error("RGB values wrong (missing input)");
	while (values[i] && ft_isspace(values[i]))
		i++;
	if (values[i])
		exit_error("RGB values wrong (extra characters)");
}
