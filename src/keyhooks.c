/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:14:13 by gade-oli          #+#    #+#             */
/*   Updated: 2024/04/08 15:22:25 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/**
 * in charge of closing the window whenever 
 * the red cross button is pressed by the user
 */
int	deal_close(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx->ptr, fdf->mlx->win);
	mlx_destroy_window(fdf->mlx->ptr, fdf->mlx->win);
	exit(SUCCESS);
	return (SUCCESS);
}

int deal_key_translation(int key, t_fdf *fdf)
{
	if (key == PGUP)
		fdf->map->translation_y -= TRANSLATION_SHIFT;
	if (key == PGDOWN)
		fdf->map->translation_y += TRANSLATION_SHIFT;
	if (key == PGRIGHT)
		fdf->map->translation_x += TRANSLATION_SHIFT;
	if (key == PGLEFT)
		fdf->map->translation_x -= TRANSLATION_SHIFT;
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
		zoom_map(fdf->map, PLUS);
	if (key == MINUS)
		zoom_map(fdf->map, MINUS);
	if (key == M)
		fdf->map->altitude += ALTITUDE_SHIFT;
	if (key == N)
		fdf->map->altitude -= ALTITUDE_SHIFT;
	if (key == R)
		init_params(fdf);
	if (key == Z)
	{
		if (fdf->map->show_instructions == ON)
			fdf->map->show_instructions = OFF;
		else
			fdf->map->show_instructions = ON;
	}
	deal_key_translation(key, fdf);
	if (key >= KEY_1 && key <= KEY_2)
		color_map(key, fdf);
	//printf("key = %d\n", key);
	display_fdf(fdf);
	return (SUCCESS);
}
