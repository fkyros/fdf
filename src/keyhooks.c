/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:14:13 by gade-oli          #+#    #+#             */
/*   Updated: 2024/01/18 12:30:53 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

//TODO: hacer un free generico para cuando acabe todo, haciendo free de la mlx y fdf

/**
 * executed when a mouse click is done INSIDE the display
 */
int	deal_click(int click, int x, int y, t_fdf *fdf)
{
	if (click)
		ft_printf("click id: %d\nx: %d\ny: %d\n", click, x, y);
	(void)fdf;
	return (0);
}

int	deal_close(t_fdf *fdf)
{
	ft_printf("bye!\n");
	mlx_clear_window(fdf->mlx->ptr, fdf->mlx->win);
	mlx_destroy_window(fdf->mlx->ptr, fdf->mlx->win);
	exit(0);
	return (0);
}

int	deal_key(int key, t_fdf *fdf)
{
	ft_printf("DEBUG -> key pressed: %d\n", key); //TODO: erase when finish debug phase
	if (key == ESC)
	{
		deal_close(fdf);
		return (SUCCESS);
	}
	if (key == P)
		fdf->map->perspective = 30;
	if (key == PLUS)
		fdf->map->zoom += 5;
	if (key == MINUS)
		fdf->map->zoom -= 5;
	if (key == M)
		fdf->map->ceiling += 5;
	if (key == N)
		fdf->map->ceiling -= 5;
	display_fdf(fdf);
	return (SUCCESS);
}
