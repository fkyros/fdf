/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:04:57 by gade-oli          #+#    #+#             */
/*   Updated: 2024/02/01 18:06:39 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

//TODO: explain algorithm and demonstration on README

t_point	get_point(t_map *map, int x, int y)
{
	t_point	point;
	int		z;
	int 	temp_x = 0;
	int		temp_y = 0;

	point.x = x;
	point.y = y;
	point.color = WHITE; 
	apply_zoom(map, &point);
	z = map->z_matrix[y][x];

	temp_x = (point.x - point.y) * cos(map->perspective);
    temp_y = (point.x + point.y) * sin(map->perspective);
	temp_y += apply_altitude(map, x, y);
	
	point.x = temp_x + (WIN_WIDTH - (map->width * cos(map->perspective) * map->zoom)) / 2;
	point.y = temp_y + (WIN_HEIGHT - (map->height * sin(map->perspective) * map->zoom)) / 2;
	return (point);
}

void    bresenham(t_fdf *fdf, t_point from, t_point to)
{
	t_point	diff;
	t_point	sign;
	t_point	point;
	int		err;
	int		tmp;

	//TODO: mover a funcion auxiliar
	diff.x = ft_abs(to.x - from.x);
	diff.y = ft_abs(to.y - from.y);
	sign.x = -1;
	sign.y = -1;
	if (from.x < to.x)
		sign.x = 1;
	if (from.y < to.y)
		sign.y = 1;

	point.x = from.x;
	point.y = from.y;
	point.color = WHITE;
	err = diff.x - diff.y; //decision parameter to know in which direction move (x or y) in each step (dx - dy its convention)
	//in each instance, the mesh point nearest to the desired line segment is selected
	while (!(point.x == to.x && point.y == to.y))
	{
		img_pixel_put(fdf->mlx, point); //paint
		tmp = err * 2; //used for optimization in the algo: removes redundant operations
		if (tmp > - diff.y)
		{
			point.x += sign.x;
			err -= diff.y; //we reduce the error since we are getting closer to the final y
		}
		if (tmp < diff.x)
		{
			point.y += sign.y;
			err += diff.x;
		}
	}
}
