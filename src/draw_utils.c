/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:47:40 by gade-oli          #+#    #+#             */
/*   Updated: 2024/01/18 14:01:51 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/**
 * applies the zoom factor to any given point
 */
void	apply_zoom(t_map *map, t_point *point)
{
	point->x *= map->zoom;
	point->y *= map->zoom;
}

/**
 * returns the modified value for the y coordinate, applying z dimension
 */
int	apply_altitude(t_map *map, int prev_x, int prev_y)
{
	int	z;
	int	altitude;

	z = map->z_matrix[prev_y][prev_x];
	altitude = -z * map->altitude;
	return (altitude);
}
