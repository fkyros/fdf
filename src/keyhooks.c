/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:14:13 by gade-oli          #+#    #+#             */
/*   Updated: 2024/02/19 16:54:16 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/**
 * in charge of closing the window whenever 
 * the red cross button is pressed by the user
 */
int	deal_close(t_fdf *fdf)
{
	ft_printf("bye!\n");
	ft_printf(" - gade-oli :)\n");
	mlx_clear_window(fdf->mlx->ptr, fdf->mlx->win);
	mlx_destroy_window(fdf->mlx->ptr, fdf->mlx->win);
	exit(SUCCESS);
	return (SUCCESS);
}

int	deal_key(int key, t_fdf *fdf)
{
	if (key == ESC)
		return (deal_close(fdf));
	if (key == P)
		fdf->map->perspective = DEG45INRAD;
	if (key == I)
		fdf->map->perspective = DEG30INRAD;
	if (key == PLUS)
		fdf->map->zoom += ZOOM_SHIFT;
	if (key == MINUS)
		fdf->map->zoom -= ZOOM_SHIFT;
	if (key == M)
		fdf->map->altitude += 2;
	if (key == N)
		fdf->map->altitude -= 2;
	if (key == R)
		init_params(fdf);
	if (key == Z)
	{
		if (fdf->map->show_instructions == ON)
			fdf->map->show_instructions = OFF;
		else
			fdf->map->show_instructions = ON;
	}
	display_fdf(fdf);
	return (SUCCESS);
}
