/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:04:57 by gade-oli          #+#    #+#             */
/*   Updated: 2024/01/03 20:50:02 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

//TODO: explain algorithm and demonstration on README

t_point	get_point(t_map *map, int x, int y)
{
	t_point	point;
	int		z;

	//add space between points
	point.x = x * map->zoom;
	point.y = y * map->zoom;
	z = map->z_matrix[y][x];
	//TODO: add isometric
	int temp_x = 0, temp_y = 0;
	if (map->perspective == 30)
	{
		temp_x = (point.x - point.y) * cos(DEG30INRAD);
    	temp_y = (-z * map->ceiling) + (point.x + point.y) * sin(DEG30INRAD); //-z parameter adds cealing (or fictional height) to the figure
	}
	else if (map->perspective == 45)
	{
		temp_x = (point.x - point.y) * cos(DEG45INRAD); 
    	temp_y = (-z * map->ceiling) + (point.x + point.y) * sin(DEG45INRAD); //-z parameter adds cealing (or fictional height) to the figure
	}
	point.x = temp_x;
	point.y = temp_y;
	//point.y = (WIN_HEIGHT / 2) - z + temp_y; //translate the figure to the center
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
