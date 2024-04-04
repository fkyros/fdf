/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:35:49 by gade-oli          #+#    #+#             */
/*   Updated: 2024/03/28 18:21:59 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/**
 * executed when a mouse click is done INSIDE the display
 */
int	deal_click(int click, int x, int y, t_fdf *fdf)
{
	if (!click)
		return (FAIL);
	fdf->mouse->click = click;
	fdf->mouse->x = x;
	fdf->mouse->y = y;
	if (click == MOUSEUP)
		fdf->map->zoom += ZOOM_SHIFT;
	if (click == MOUSEDOWN)
		fdf->map->zoom -= ZOOM_SHIFT;
	display_fdf(fdf);
	return (SUCCESS);
}
