/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:04:57 by gade-oli          #+#    #+#             */
/*   Updated: 2023/12/27 21:01:21 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

//TODO: explain algorithm and demonstration on README

t_point	get_point(t_map *map, int x, int y)
{
	t_point	point;

	point.x = x * map->zoom;
	point.y = y * map->zoom;
	//TODO: add isometric
	//int temp_x = (point.x - point.y) * cos(0.78539816); //cos(30º)
    //int temp_y = (point.x + point.y) * sin(0.78539816);
    //point.x = temp_x;
    //point.y = temp_y;
	return (point);
}

void    bresenham(t_fdf *fdf, t_point from, t_point to)
{
	t_point	diff;
	t_point	sign;
	t_point	point;
	int		err;
	int		tmp;
	
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
	err = diff.x - diff.y; //decision parameter to know in which direction move (x or y) in each step (dx - dy its convention)
	//in each instance, the mesh point nearest to the desired line segment is selected
	while (point.x != to.x || point.y != to.y)
	{
		img_pixel_put(fdf->mlx, point.x, point.y); //paint
		tmp = err * 2; //used for optimization in the algo: removes redundant operations
		if (tmp > - diff.y) //
		{
			point.x += sign.x; //
			err -= diff.y; //we reduce the error since we are getting closer to the final y
		}
		if (tmp < diff.x)
		{
			point.y += sign.y;
			err += diff.x;
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
