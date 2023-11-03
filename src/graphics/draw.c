/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:04:57 by gade-oli          #+#    #+#             */
/*   Updated: 2023/11/03 19:06:14 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

//TODO: explain algorithm and demonstration on README

void	bresenham(int x1, int y1, int x2, int y2, t_mlx *mlx)
{
	int	dx;
	int	dy;
	int	dp;
	int	x;
	int	y;

	x = x1;
	y = y1;
	dp = 2 * (y2 - y) - (x2  - x);
	while (!(x == x2 && y == y2))
	{
		dx = x2 - x;
		dy = y2 - y;
		if (dp > 0)
		{
			dp = dp + 2*dy - 2*dx;
			x++;
		}
		else
			dp = dp + 2*dy;
		y++;
		my_pixel_put(mlx, x, y);
		ft_printf("drawn (%d, %d)\n", x, y);
	}
}
