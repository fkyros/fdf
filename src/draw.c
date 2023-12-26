/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:04:57 by gade-oli          #+#    #+#             */
/*   Updated: 2023/12/26 23:21:56 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

//TODO: explain algorithm and demonstration on README

t_point	get_point(t_map *map, int x, int y)
{
	t_point	point;

	point.x = x * map->zoom;
	point.y = y * map->zoom;
	//TODO: add isometric
	return (point);
}

void    bresenham(t_fdf *fdf, t_point from, t_point to)
{
	int	dx = ft_abs(to.x - from.x);
	int dy = ft_abs(to.y - from.y);
	int x_sign = -1;
	int y_sign = -1;
	if (from.x < to.x)
		x_sign = 1;
	if (from.y < to.y)
		y_sign = 1;

	int x = from.x;
	int y = from.y;
	int err = dx - dy;
	int tmp;
	while (x != to.x || y != to.y)
	{
		my_pixel_put(fdf->mlx, x, y);
		tmp = err * 2;
		if (tmp > -dy)
		{
			err -= dy;
			x += x_sign;
		}
		if (tmp < dx)
		{
			err += dx;
			y += y_sign;
		}
	}
}

void	draw_map(t_fdf *fdf)
{
	int	x;
	int y;

	y = 0;
	if (!fdf->map->zoom)
		return ;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			if (x < fdf->map->width - 1)
				bresenham(fdf, get_point(fdf->map, x, y), get_point(fdf->map, x + 1, y));
			if (y < fdf->map->height - 1)
				bresenham(fdf, get_point(fdf->map, x, y), get_point(fdf->map, x, y + 1));
			x++;
		}
		y++;
	}
}
