/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:04:57 by gade-oli          #+#    #+#             */
/*   Updated: 2024/04/08 17:52:39 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/**
 * takes a (x,y) from the map, applies zoom, rotation and 
 * translation for the given perspective, extracts its
 * z value from the map giving the altitude for each point,
 * and centers it to the middle of the display
 */
t_point	get_point(t_map *map, int x, int y)
{
	t_point	point;
	int		z;
	int		temp_x;
	int		temp_y;

	temp_x = 0;
	temp_y = 0;
	z = map->z_matrix[y][x];
	point.x = x * map->zoom;
	point.y = y * map->zoom;
	temp_x = (point.x - point.y) * cos(map->perspective);
	temp_y = (point.x + point.y) * sin(map->perspective);
	temp_y += -z * map->altitude;
	point.x = temp_x + map->translation_x;
	point.y = temp_y + map->translation_y;
	return (point);
}

void	setup_bresenham(t_point *p, t_point *dir, t_point *from, t_point *to)
{
	p->x = from->x;
	p->y = from->y;
	dir->x = -1;
	dir->y = -1;
	if (from->x < to->x)
		dir->x = 1;
	if (from->y < to->y)
		dir->y = 1;
}

void	bresenham(t_fdf *fdf, t_point from, t_point to)
{
	t_point	point;
	t_point	diff;
	t_point	dir;
	int		err;
	int		factor;

	setup_bresenham(&point, &dir, &from, &to);
	diff.x = ft_abs(to.x - from.x);
	diff.y = ft_abs(to.y - from.y);
	err = diff.x - diff.y;
	while (!(point.x == to.x && point.y == to.y))
	{
		point.color = fdf->map->line_color;
		img_pixel_put(fdf->mlx, point);
		factor = err * 2;
		if (factor > -diff.y)
		{
			point.x += dir.x;
			err -= diff.y;
		}
		if (factor < diff.x)
		{
			point.y += dir.y;
			err += diff.x;
		}
	}
}
