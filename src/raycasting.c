/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomez-f <tgomez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 10:56:30 by tgomez-f          #+#    #+#             */
/*   Updated: 2026/01/30 16:46:01 by tgomez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

#define COLOR_WALL 0x777777
#define COLOR_FLOOR 0x111111
#define COLOR_PLAYER 0xFF0000
#define COLOR_DIR 0x00FF00
#define COLOR_RAY 0xFFFF00

static void	put_pixel(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = mlx->buffer + (y * mlx->size_line + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	draw_square(t_mlx *mlx, int x, int y, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			put_pixel(mlx, x + j, y + i, color);
			j++;
		}
		i++;
	}
}
static void	draw_line(t_mlx *mlx, int x0, int y0, int x1, int y1, int color)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	dx = abs(x1 - x0);
	dy = -abs(y1 - y0);
	sx = x0 < x1 ? 1 : -1;
	sy = y0 < y1 ? 1 : -1;
	err = dx + dy;
	while (1)
	{
		put_pixel(mlx, x0, y0, color);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

static void	draw_map_2d(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map->map_grid[y])
	{
		x = 0;
		while (data->map->map_grid[y][x])
		{
			if (data->map->map_grid[y][x] == '1')
				draw_square(data->mlx, x * TILE, y * TILE, TILE, COLOR_WALL);
			else
				draw_square(data->mlx, x * TILE, y * TILE, TILE, COLOR_FLOOR);
			x++;
		}
		y++;
	}
}
static void	draw_player(t_data *data)
{
	int	x;
	int	y;

	x = data->player.pos.x * TILE;
	y = data->player.pos.y * TILE;
	draw_square(data->mlx, x - 2, y - 2, 4, COLOR_PLAYER);
}

static void	draw_player_dir(t_data *data)
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;

	x0 = data->player.pos.x * TILE;
	y0 = data->player.pos.y * TILE;
	x1 = (data->player.pos.x + data->player.dir.x) * TILE;
	y1 = (data->player.pos.y + data->player.dir.y) * TILE;
	draw_line(data->mlx, x0, y0, x1, y1, COLOR_DIR);
}
static void	draw_debug_ray(t_data *data)
{
	double	rayX;
	double	rayY;

	rayX = data->player.pos.x;
	rayY = data->player.pos.y;
	while (data->map->map_grid[(int)rayY][(int)rayX] != '1')
	{
		rayX += data->player.dir.x * 0.05;
		rayY += data->player.dir.y * 0.05;
		put_pixel(data->mlx, rayX * TILE, rayY * TILE, COLOR_RAY);
	}
}

void	debug_ray(t_data *data)
{
	draw_map_2d(data);
	draw_player(data);
	draw_player_dir(data);
	draw_debug_ray(data);
}

void	raycasting(t_data *data)
{
	debug_ray(data);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->window, data->mlx->img,
		0, 0);
}
//int	render(void *param)
//{
//	t_data	*data;

//	data = (t_data *)param;
//	raycasting(data);
//	return (0);
//}
