/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:14:13 by gade-oli          #+#    #+#             */
/*   Updated: 2024/01/02 22:03:20 by gade-oli         ###   ########.fr       */
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
		//print_instructions(fdf->mlx);
	(void)fdf;
	return (0);
}

int	deal_red_button(t_fdf *fdf)
{
	ft_printf("bye!\n");
	mlx_clear_window(fdf->mlx->ptr, fdf->mlx->win);
	mlx_destroy_window(fdf->mlx->ptr, fdf->mlx->win);
	exit(0);
	return (0);
}

int	deal_key(int key, t_fdf *fdf)
{
	//TODO: check if the key pressed is valid
	ft_printf("key pressed: %d\n", key);
	if (key == ESC)
	{
		mlx_clear_window(fdf->mlx->ptr, fdf->mlx->win);
		mlx_destroy_window(fdf->mlx->ptr, fdf->mlx->win);
		exit(0);
	}
	(void)fdf;
	return (0);
}
