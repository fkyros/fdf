/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:19:01 by gade-oli          #+#    #+#             */
/*   Updated: 2024/02/01 19:25:54 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/**
 * initialises map visual parameters 
 * that can later be changed through mlx events
*/
void	init_map_params(t_map *map)
{
	map->zoom = ZOOM;
	map->altitude = 2;
	map->perspective = DEG30INRAD;
	map->show_instructions = ON;
}

/**
 * clears the screen and draws the 
 * fdf figure given the map parameters
*/
void	display_fdf(t_fdf *fdf)
{
	clear_window(fdf->mlx);
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx->ptr, fdf->mlx->win, \
			fdf->mlx->img, 0, 0);
	if (fdf->map->show_instructions)
		print_instructions(fdf->mlx);
}

/**
 * draws the fdf figure read from the input file
 */
void	draw_map(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	if (!fdf->map->zoom)
		return ;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			if (x < fdf->map->width - 1)
				bresenham(fdf, get_point(fdf->map, x, y), \
						get_point(fdf->map, x + 1, y));
			if (y < fdf->map->height - 1)
				bresenham(fdf, get_point(fdf->map, x, y), \
						get_point(fdf->map, x, y + 1));
			x++;
		}
		y++;
	}
}
