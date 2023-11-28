/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:04:57 by gade-oli          #+#    #+#             */
/*   Updated: 2023/11/24 14:56:14 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

//TODO: explain algorithm and demonstration on README

int positive(int x)
{
	if (x < 0)
		return (x*-1);
	return (x);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	bresenham(int x1, int y1, int x2, int y2, t_fdf *fdf)
{
	int	dx;
	int	dy;
	int	x;
	int	y;
	int max_d;
	int color;	
	int z = 0;

	//zoom
	x1 *= fdf->map->zoom;
	y1 *= fdf->map->zoom;
	x2 *= fdf->map->zoom;
	y2 *= fdf->map->zoom;

	dx = x1 - x2;
	dy = y1 - y2;
	x = x2;
	y = y2;
	max_d = max(positive(dx), positive(dy));
	dx /= max_d;
	dy /= max_d;

	//color
	if (x2 <= fdf->map->width && y2 <= fdf->map->height)
		z = fdf->map->z_matrix[y2][x2];
	if (z > 0)
		color = 0x00FF0000;
	else
		color = 0x00FFFFFF;

	// Isometric transformation
	x1 = (x1 - y1) * cos(0.523599);
	y1 = (x1 + y1) * sin(0.523599);
	x2 = (x2 - y2) * cos(0.523599);
	y2 = (x2 + y2) * sin(0.523599);

	while ((x - x1) || (y - y1))
	{
		my_pixel_put(fdf->mlx, x, y, color);
		x += dx;
		y += dy;
	}
}

void	draw_map(t_fdf *fdf)
{
	int	i;
	int j;

	j = 0;
	while (j < fdf->map->height)
	{
		i = 0;
		while (i < fdf->map->width)
		{
			if (i < fdf->map->width - 1)
				bresenham(i, j, i + 1, j, fdf);
			if (j < fdf->map->height - 1)
				bresenham(i, j, i, j + 1, fdf);
			i++;
		}
		j++;
	}
}
