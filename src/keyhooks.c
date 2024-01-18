/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:14:13 by gade-oli          #+#    #+#             */
/*   Updated: 2024/01/18 15:36:56 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/**
 * executed when a mouse click is done INSIDE the display
 */
int	deal_click(int click, int x, int y, t_fdf *fdf)
{
	if (click)
		ft_printf("click id: %d\nx: %d\ny: %d\n", click, x, y);
	if (click == MOUSEUP)
		fdf->map->zoom += 5;
	if (click == MOUSEDOWN)
		fdf->map->zoom -= 5;
	display_fdf(fdf);
	return (SUCCESS);
}

/**
 * in charge of closing the window whenever 
 * the red cross button is pressed by the user
 */
int	deal_close(t_fdf *fdf)
{
	ft_printf("bye!\n");
	mlx_clear_window(fdf->mlx->ptr, fdf->mlx->win);
	mlx_destroy_window(fdf->mlx->ptr, fdf->mlx->win);
	exit(0);
	return (SUCCESS);
}

int	deal_key(int key, t_fdf *fdf)
{
	if (key == ESC)
		return (deal_close(fdf));
	if (key == P)
		fdf->map->perspective = DEG30INRAD;
	if (key == PLUS)
		fdf->map->zoom += 5;
	if (key == MINUS)
		fdf->map->zoom -= 5;
	if (key == M)
		fdf->map->altitude += 2;
	if (key == N)
		fdf->map->altitude -= 2;
	if (key == R)
		init_map_params(fdf->map);
	display_fdf(fdf);
	return (SUCCESS);
}
